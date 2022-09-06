# FDF

A simple 3D wireframe rasterizer written in C with MinilibX library. FdF renders 3D models contained in a specific .fdf format. 
Two distinct forms of projection are supported (isometric and perspective). 

### Features:
  * zoom 
  * panning 
  * simple rotation 
  * scaling up/down
  * full screen
  * close window (stop program)
  * vertical coloration
  * reading colors from maps <sub>(where colors for eahh point are presented in hex after `,`)</sub>
  * usage pannel

### Requirements
To run the program MinilibX needs to be installed.
- MacOS: https://github.com/dannywillems/minilibx-mac-osx
- Linux: https://github.com/42Paris/minilibx-linux

### Examples

42.fdf
<img width="2032" alt="Screen Shot 2022-09-06 at 6 06 24 PM" src="https://user-images.githubusercontent.com/84226106/188675304-b1784d14-0f0c-46bf-a978-c12a21c15d81.png">

julia.fd (2D representation)
<img width="2032" alt="Screen Shot 2022-09-06 at 6 45 08 PM" src="https://user-images.githubusercontent.com/84226106/188679563-20fd824b-e6bb-4047-98dc-22dbc53cabdc.png">

julia.fd (3D representation, down scale)
<img width="2032" alt="Screen Shot 2022-09-06 at 6 45 45 PM" src="https://user-images.githubusercontent.com/84226106/188679640-f4461add-ee15-4bec-bee2-6864919b937e.png">

mars.fd (3D representation, up scale, rotated)
<img width="2672" alt="Screen Shot 2022-09-06 at 6 46 55 PM" src="https://user-images.githubusercontent.com/84226106/188679674-b0ad48a3-20aa-4bd8-a7b7-225b6b9ebca7.png">

### Map input example 
