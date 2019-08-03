# duilib_xiaonaiquan
duilib

### 腾讯修改的duilib版本
https://github.com/tencentyun/TIMSDK/tree/master/cross-platform/Windows/IMApp/Basic/duilib

1.修复的菜单无法使用bug
2.修复鼠标手势的改变
3.修复托盘图标

修复方案：
http://blog.csdn.net/xiaonaiquan/article/category/6986587

4.修改了js和C++的交互，数据传递的正确性，C++调用js函数用什么数据类型将数据传递过去，之前写的存在数据对象可能已经不在的bug，编译的是debug版本。

5.增加了Dpi Demo，来适应各种DPi 下的程序状态

6.将treeview默认状态改为收缩状态

7.增加图片旋转控件，来自juhuaguai

8.修复了RichEdit中有链接时，无法响应LINK事件

