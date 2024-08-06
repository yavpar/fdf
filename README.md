/* ************************************************************************ */
/*	THIS PROGRAM FDF "FIL DE FER" READS A FILE AND DRAW LINES.				      */
/*	FIRST IT PARSES THE FILE AND CREATES A CHAR *** (3D ARRAY) IN WITCH		  */
/*	IT CONTAINS THE DATA OF SUCH FILE: COORDINATES X, Y, Z AND EVENTUALLY	  */
/*	A COLOR IN OPTION. 														                          */
/*	FOR EACH ITERATION OF THE 3D ARRAY IT CALCULATES 4 VECTOR POINTS 		    */
/*	AND DRAW 2 WHITE LINES:													                        */
/*	LINE 1: P1(X, Y) P2(X + 1, Y) (HORIZONTAL)								              */
/*	LINE 2: P2(X, Y) P4(X, Y + 1) (VERTIACL)								                */
/*	THE IMAGE SHOWN IS IN ISOMETRIC PROJECTION								              */
/*	ITS USES MLX LIBRARY IN ORDER TO CREAT A WINDOW TO DRAW THE LINES		    */
/* ************************************************************************ */
