# LVGL模拟器

环境准备：

- 下载好cmake，安装并配置好环境变量。
- 下载好MinGW，配置好环境变量。
- 下载VSCode，配置好C/C++环境（C/C++的三个插件、cmake的两个插件，需要的话配置好MinGW的路径、cmake的路径）。
- 下载好SDL2（SDL2-devel-2.28.5-mingw），配置进MinGW中（将下载好的SDL2文件里的cmake文件夹和x86_64-w64-mingw32文件夹复制到MinGW的目录）。

LVGL：

- 下载好lv_port_pc_eclipse。
- 下载好lv_port_pc_eclipse里的lv_drivers和lvgl，并将里面的代码放入到lv_port_pc_eclipse里的lv_drivers和lvgl中。
- 用VSCode打开目录，点击生成，就会生成一个bin目录，里面生成了一个main.exe，然后将将下载好的SDL2文件里的x86_64-w64-mingw32文件夹中的SDL2.dll放到bin目录里，就可以点击main.exe来模拟LVGL了。



# LVGL

图层：act_scr、top_layer、sys_layer。

控件：放于act_scr层；控件的样式——大小、尺寸、位置、对齐方式、外观样式。

基础控件：label、button、img、button matrix、text area。

思想：层 → 屏幕 → 控件，通过属性、样式来实现个性化。事件用于触发操作。

事件触发方式：单击、长按、滑动（上、下、左、右）。



















