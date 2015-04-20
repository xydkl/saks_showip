# saks_showip
树莓派上安装SAKS瑞士军刀后,在四位数码管上显示ip地址
# 依赖
需要提前安装wiringPi
# 开机启动
sudo cp showip /usr/local/bin/
sudo vim /etc/rc.local
在exit 0 前添加 
showip &
