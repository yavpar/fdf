#include <mlx.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}              t_data;

typedef struct s_point {
    int x;
    int y;
    int color;
}              t_point;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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

int main(void) {
    t_data  img;
    t_point point_a = {100, 100, 0x00FF0000}; // Rojo
    t_point point_b = {700, 500, 0x0000FF00}; // Verde

    img.mlx_ptr = mlx_init();
    img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "MLX Window");
    img.img_ptr = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);

    draw_line(&img, point_a, point_b);

    mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img_ptr, 0, 0);
    mlx_loop(img.mlx_ptr);

    return 0;
}

