# HMM_viterbi
C语言版本的HMM viterbi算法demo

HMM（隐马尔可夫模型）是用来描述隐含未知参数的统计模型，举一个经典的例子：一个东京的朋友每天根据天气{下雨，天晴}决定当天的活动{公园散步,购物,清理房间}中的一种，我每天只能在twitter上看到她发的推“啊，我前天公园散步、昨天购物、今天清理房间了！”，那么我可以根据她发的推特推断东京这三天的天气。在这个例子里，显状态是活动，隐状态是天气。

任何一个HMM都可以通过下列五元组来描述：

:param obs:观测序列
:param states:隐状态
:param start_p:初始概率（隐状态）
:param trans_p:转移概率（隐状态）
:param emit_p: 发射概率 （隐状态表现为显状态的概率）

求解最可能的天气
求解最可能的隐状态序列是HMM的三个典型问题之一，通常用维特比算法解决。维特比算法就是求解HMM上的最短路径（-log(prob)，也即是最大概率）的算法。

稍微用中文讲讲思路，很明显，第一天天晴还是下雨可以算出来：

1.定义V[时间][今天天气] = 概率，注意今天天气指的是，前几天的天气都确定下来了（概率最大）今天天气是X的概率，这里的概率就是一个累乘的概率了。

2.因为第一天我的朋友去散步了，所以第一天下雨的概率V[第一天][下雨] = 初始概率[下雨] * 发射概率[下雨][散步] = 0.6 * 0.1 = 0.06，同理可得V[第一天][天晴] = 0.24 。从直觉上来看，因为第一天朋友出门了，她一般喜欢在天晴的时候散步，所以第一天天晴的概率比较大，数字与直觉统一了。

3.从第二天开始，对于每种天气Y，都有前一天天气是X的概率 * X转移到Y的概率 * Y天气下朋友进行这天这种活动的概率。因为前一天天气X有两种可能，所以Y的概率有两个，选取其中较大一个作为V[第二天][天气Y]的概率，同时将今天的天气加入到结果序列中

4.比较V[最后一天][下雨]和[最后一天][天晴]的概率，找出较大的哪一个对应的序列，就是最终结果。