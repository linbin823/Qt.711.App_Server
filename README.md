# APP Server  
2017.06  

## 功能：  

1、数据驱动组态、编辑  
2、数据测点组态、编辑、修改  
3、数据Web服务  

## 初始化工作：  

1、clone到本地文件夹：git clone ...  
2、初始化submodule： git submodule update --init --remote --recursive -f  
3、Qt的工程文件位于：./src/Drivers/Drivers.pro  
4、使用QtCreator打开工程文件，编译（因为是驱动库，不能运行）  
5、找到编译输出文件夹，其上一级目录中有一个Drivers目录，把这个目录复制到 ./build/App_Server/"your_plateform"/ 中（可能会询问是否覆盖，选则是）。（要把"your_plateform"替换成你需要的平台目录，下同）  
6、可执行文件位于 ./build/App_Server/"your_plateform"/App_Server.exe。  
7、对于Windows平台。执行App_Server，可能会遇到dll丢失等问题。如果报错说dll找不到，请找到 Qt安装目录/bin/中的windeployqt.exe。在命令行中输入windeployqt.exe，后面加一个空格，空格后面是App_Server.exe的完整路径。执行后，Qt会自动补全所有需要的dll。
8、运行App_Server，打开驱动管理器，就可以看到所有驱动。   

## App_Server支持平台：（可以在 build/App_Server/ 目录中查看 ）

1、GCC64bit2 + Desktop Linux + Qt5.10.0  
2、MingW32bit + Windows + Qt5.9.X  

## 新增驱动：

1、可以参考任何现有驱动为模板  
2、需要严格满足要求：	继承自iDriver接口 （ToDo）  
