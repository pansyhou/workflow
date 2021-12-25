# Student Information Comprehensive Management System linked version

## 1.框图构思

* 对结构体链表的操作文件linker.c\linker.h
  * 开辟内存addmm
  * 增加节点addlinker
  * 遍历输出节点printLinked
  * 释放内存killmem
  * 复制节点cpylinked
  * 排序链表sortlinked
  * 删除节点deleteLinker
* 对管理系统的数据的增加add()
* 对管理系统的数据的修改change()
* 对管理系统的数据的删除delete()
* 对管理系统的数据的浏览browse()
* 对管理系统的数据的查找seach()
* 对管理系统的数据的排序sort()
* 对管理系统的数据的统计statistics()
* 对管理系统的数据的保存save()
* main()


something wanna say:

```
其实你综合看代码看下来其实会很乱，因为linker,c里写了一些关于链表的操作，但是主的c文件zonghe.c又有一些是关于链表的操作，少量，但是也多。
```


```
一开始有着对程序架构的完美蓝图，但是在具体写程序的时候你会发现，不实际。还是要多加练习，真的就是不熟练，对变量的生命周期一点都不熟悉，调试了两个下午，直到周六晚上突破了变量的问题才开始写主函数。
```


```
写完这个项目之后不禁感叹，想去搞项目了，只有项目才能摆脱很多坏习惯，比如变量名乱写（看我的变量，是不是全是什么head/prev/before/current之类的，虽然说方便我移植，但是要是在项目里说不定会被打死，太多重名的了。而且注释也不写完全=>
```
