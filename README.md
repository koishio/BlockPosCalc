# BlockPosCalc

**English** | [简体中文](README_cn.md)

## Introduction:

Simple Block Coordinate Calculator  
Used to calculate the coordinates of shapes such as circles  

## Background:

It is always hard to build a circle in minecraft  
So I made this calculator to make it convenient for myself and for everyone to use  
Enter the center and radius of the circle  
This program will show the coordinates of the upper right part of the circle  
At the moment there are only circles, and other shapes may be added in the future (if I need it)  

## Usage:

1. Download it from Realese
2. Double-click exe file

## Description of the output:

`x` and `y` are the coordinates of the blocks on the circle  
`disp_x` and `disp_y` is the coordinate of each point on the circle when the center coordinate of the circle is `(0,0)`  
`count` is how many blocks there are at the same height  
When the ordinate changes, the color will also change for easy identification  
In the last 45°, there may be a vertical column of blocks on the circle, and the result shows the top block  
Since the axis of symmetry in the upper right part is a straight line with a horizontal declination angle of 45°  
the rest of the part can be easily built according to the symmetry  

## Build

Open the solution by Visual Studio 2022 and build it generally  