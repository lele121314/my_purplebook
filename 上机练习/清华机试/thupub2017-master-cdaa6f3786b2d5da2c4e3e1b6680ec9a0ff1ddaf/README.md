# THUPUB2017

在`git clone`的时候加上`--recursive`可以一并把这个子工程拿下来：
```bash
git lfs clone --recursive git@git.thusaac.org:publish/thupub2017.git
```
若未装`lfs`，使用`git clone`下来的数据只是一个指针，因此必须安装`git lfs`。第一次使用参考[这里](https://github.com/git-lfs/git-lfs/wiki/Installation)安装。

若已安装`lfs`，推荐使用`git lfs clone`命令，该命令会将大文件打包下载，而使用`git lfs`命令则会逐一下载文件，消耗更多流量。欢迎加入算协获取无限流量账号～

**更详细的内容见[oi_tools](http://git.thusaac.org/mulab/oi_tools)子工程的介绍。**