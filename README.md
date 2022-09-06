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

cliff.fdf (3D, rotated, colors read from the map)
<img width="2672" alt="Screen Shot 2022-09-06 at 7 03 04 PM" src="https://user-images.githubusercontent.com/84226106/188683089-c00447a7-5dfe-4522-81b8-890b057a1b90.png">

julia.fd (2D representation)
<img width="2032" alt="Screen Shot 2022-09-06 at 6 45 08 PM" src="https://user-images.githubusercontent.com/84226106/188679563-20fd824b-e6bb-4047-98dc-22dbc53cabdc.png">

julia.fd (3D representation, down scale)
<img width="2032" alt="Screen Shot 2022-09-06 at 6 45 45 PM" src="https://user-images.githubusercontent.com/84226106/188679640-f4461add-ee15-4bec-bee2-6864919b937e.png">

mars.fd (2D representation, up scale, rotated)
<img width="2672" alt="Screen Shot 2022-09-06 at 6 46 55 PM" src="https://user-images.githubusercontent.com/84226106/188679674-b0ad48a3-20aa-4bd8-a7b7-225b6b9ebca7.png">

mars.fd (3D representation, up scale, zoomed in, rotated)
<img width="2672" alt="Screen Shot 2022-09-06 at 6 48 02 PM" src="https://user-images.githubusercontent.com/84226106/188680935-f5e18842-bf1c-4a57-9ea3-79d9bf36f341.png">

### Map input example

pyramide.fdf
<img width="1286" alt="Screen Shot 2022-09-06 at 6 55 14 PM" src="https://user-images.githubusercontent.com/84226106/188681124-b977f4fd-cbba-4083-86b9-489e0ddf95c8.png">

pyramide.fdf <sub>(result, up-scaled, zoomed, rotated)</sub> 
Note, that colors change depending on height but top is always **white**, because the map states the color. 
<img width="2032" alt="Screen Shot 2022-09-06 at 6 58 09 PM" src="https://user-images.githubusercontent.com/84226106/188682651-831fd841-6f39-410e-8fc2-50593f9efb37.png">
