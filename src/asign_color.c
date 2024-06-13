/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:36:49 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/13 12:36:58 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_point {
    int x;
    int y;
    int z;
    int color;
} t_point;

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int interpolate(int start, int end, float ratio) {
    return start + (end - start) * ratio;
}

int interpolate_color(int color_start, int color_end, float ratio) {
    int red = interpolate((color_start >> 16) & 0xFF, (color_end >> 16) & 0xFF, ratio);
    int green = interpolate((color_start >> 8) & 0xFF, (color_end >> 8) & 0xFF, ratio);
    int blue = interpolate(color_start & 0xFF, color_end & 0xFF, ratio);

    return (red << 16) | (green << 8) | blue;
}

int map_value_to_color(int value, int min, int max) {
    float ratio = (float)(value - min) / (max - min);
    int color_start = 0x000000; // Black
    int color_end = 0xFFFFFF; // White
    return interpolate_color(color_start, color_end, ratio);
}

t_point **read_file(const char *filename, int *width, int *height, int *min_val, int *max_val) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    t_point **points = NULL;
    *height = 0;
    *min_val = INT_MAX;
    *max_val = INT_MIN;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        *width = 0;
        t_point *row = malloc(sizeof(t_point) * 256); // Assuming max width of 256
        while (token) {
            int z = atoi(token);
            if (z < *min_val) *min_val = z;
            if (z > *max_val) *max_val = z;
            row[*width].x = *width;
            row[*width].y = *height;
            row[*width].z = z;
            row[*width].color = -1; // Color will be assigned later
            (*width)++;
            token = strtok(NULL, " ");
        }
        points = realloc(points, sizeof(t_point *) * (*height + 1));
        points[*height] = row;
        (*height)++;
    }

    fclose(file);
    return points;
}

void assign_colors(t_point **points, int width, int height, int min_val, int max_val) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            points[y][x].color = map_value_to_color(points[y][x].z, min_val, max_val);
        }
    }
}

void draw_line(t_data *img, t_point start, t_point end) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int steps = dx > dy ? dx : dy;

    for (int i = 0; i <= steps; i++) {
        float ratio = (float)i / steps;
        int x = interpolate(start.x, end.x, ratio);
        int y = interpolate(start.y, end.y, ratio);
        int color = interpolate_color(start.color, end.color, ratio);
        my_mlx_pixel_put(img, x, y, color);
    }
}

void draw_points(t_data *img, t_point **points, int width, int height) {
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            draw_line(img, points[y][x], points[y][x + 1]);
            draw_line(img, points[y][x], points[y + 1][x]);
        }
    }
}

int main(void) {
    t_data img;
    int width, height;
    int min_val, max_val;
    t_point **points = read_file("data.txt", &width, &height, &min_val, &max_val);

    assign_colors(points, width, height, min_val, max_val);

    img.mlx_ptr = mlx_init();
    img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "MLX Window");
    img.img_ptr = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

    draw_points(&img, points, width, height);

    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img_ptr, 0, 0);
    mlx_loop(img.mlx_ptr);

    // Liberar memoria
    for (int i = 0; i < height; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}
