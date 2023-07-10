<!-- Created by Frank -->

- [00](#00)
  - [Data Mining の技術 (00b, P26)](#data-mining-の技術-00b-p26)
- [01 - 02 Hyper Text \& Web](#01---02-hyper-text--web)
  - [WWW (P2)](#www-p2)
  - [Hyper Text (P3)](#hyper-text-p3)
  - [WWW 历史 (P5)](#www-历史-p5)
  - [Hyper Text 历史 (P6)](#hyper-text-历史-p6)
  - [Internet 历史 (P7)](#internet-历史-p7)
  - [WWW 和 Internet 区别 (P18)](#www-和-internet-区别-p18)
  - [HTTP (P19)](#http-p19)
  - [Port 端口号 (P22)](#port-端口号-p22)
  - [FTP (P23)](#ftp-p23)
  - [Web Computing (P26)](#web-computing-p26)
  - [Web Application (P28)](#web-application-p28)
  - [Web Service (P56)](#web-service-p56)
  - [Mash Up (P61)](#mash-up-p61)
  - [Web Service Architecture (P67)](#web-service-architecture-p67)
- [03 - 04 Web \& 集合知](#03---04-web--集合知)
  - [什么是集合知 (P2)](#什么是集合知-p2)
  - [集合知发挥作用的条件 (P13)](#集合知发挥作用的条件-p13)
  - [Web 2.0 的 7 原则 (P20)](#web-20-的-7-原则-p20)
  - [Search Engine (P28)](#search-engine-p28)
  - [典型 Search Engine 的构成 (P38)](#典型-search-engine-的构成-p38)
  - [PageRank (P44, 有计算)](#pagerank-p44-有计算)
  - [PageRank の Point (P48)](#pagerank-の-point-p48)
  - [SEO (P51)](#seo-p51)
  - [PageRank merit (P52)](#pagerank-merit-p52)
  - [PageRank 计算 (P55)](#pagerank-计算-p55)
  - [Deep Web (P60)](#deep-web-p60)
  - [大规模化 (P63)](#大规模化-p63)
  - [Personal化 (P65)](#personal化-p65)
- [05 - 06 Web Mining](#05---06-web-mining)
  - [Big Data 分析 (P3)](#big-data-分析-p3)
  - [Web Mining (P4)](#web-mining-p4)
  - [Web Mining 手法 (P5)](#web-mining-手法-p5)
  - [Web Mining 的意义 (P12)](#web-mining-的意义-p12)
  - [Text Mining (P14)](#text-mining-p14)
  - [Text Mining の流れ (P21)](#text-mining-の流れ-p21)
  - [文章同士の比較 (P31, 有计算)](#文章同士の比較-p31-有计算)
  - [Clustering (P41, 有计算)](#clustering-p41-有计算)
- [07 - 08 複雑 Network](#07---08-複雑-network)
  - [Web Mining 手法 (P2)](#web-mining-手法-p2)
  - [Network 研究历史 (P13)](#network-研究历史-p13)
  - [Network 构造和指标 (P43, 有计算)](#network-构造和指标-p43-有计算)
- [09 - 10 协调 Filtering (协同过滤)](#09---10-协调-filtering-协同过滤)
  - [Web Mining 手法 (P3)](#web-mining-手法-p3)
  - [推荐系统是什么 (P5)](#推荐系统是什么-p5)
  - [推荐方法 (x5) (P13)](#推荐方法-x5-p13)
  - [推荐利用目的 (x4) (P14)](#推荐利用目的-x4-p14)
  - [要素技术 (P15)](#要素技术-p15)
  - [推荐历史 (P17)](#推荐历史-p17)
  - [推荐系统的实行过程 (P20, 有计算, P28)](#推荐系统的实行过程-p20-有计算-p28)
- [11 - 12 Web Security](#11---12-web-security)
  - [Web 技術のおさらい（复习）](#web-技術のおさらい复习)
  - [Web 认证](#web-认证)
  - [Web Application 的脆弱性和对策](#web-application-的脆弱性和对策)
  - [その他 (P66)](#その他-p66)
- [13 Cloud Computing](#13-cloud-computing)
  - [Cloud Computing is? (P2)](#cloud-computing-is-p2)
  - [Cloud 登场背景 (P3)](#cloud-登场背景-p3)
  - [Cloud 普及背景 (P4)](#cloud-普及背景-p4)
  - [Cloud 定义和特征 (P5 - 6)](#cloud-定义和特征-p5---6)
  - [Service Model (P7)](#service-model-p7)
  - [利用 Model (P12)](#利用-model-p12)
  - [导入 Cloud 的优点 (P13)](#导入-cloud-的优点-p13)
  - [Cloud 提供的服务 (P16)](#cloud-提供的服务-p16)
  - [Cloud Service 的 4 个 Pattern (P30)](#cloud-service-的-4-个-pattern-p30)
  - [Cloud 活用 (P31)](#cloud-活用-p31)
- [14 Access 解析 \& Internet 广告](#14-access-解析--internet-广告)
  - [Access 解析 (P2)](#access-解析-p2)
  - [Access 解析结果的应用 (P3)](#access-解析结果的应用-p3)
  - [Access Log 解析的指标 (P6)](#access-log-解析的指标-p6)
  - [同一个人的判定 (P10)](#同一个人的判定-p10)
  - [Access 解析方法 (P12)](#access-解析方法-p12)
  - [Access 解析的難しさ (P19)](#access-解析的難しさ-p19)
  - [Internet 广告 (P20)](#internet-广告-p20)
  - [Internet 广告的历史 (P30)](#internet-广告的历史-p30)
  - [Internet 广告的特征 (P50)](#internet-广告的特征-p50)
  - [Internet 广告的课题 (P51)](#internet-广告的课题-p51)

# 00

### Data Mining の技術 (00b, P26)

* Text Mining: text信息的分解
* 相关 rule 分析: 相关关系、情报 filtering、推荐系统
* Graph Mining: 关系之间的可视化

# 01 - 02 Hyper Text & Web

### WWW (P2)

* 地球规模的 hyper text、1989年提案、1991年实动、Tim Berners Lee
* 仕組み
  * HTML 文书
  * URL 唯一的识别子、指定文书页面

### Hyper Text (P3)

* 任意位置埋入 `hyper link`、1960年中顷、Ted Nelson、DMS の一つ

### WWW 历史 (P5)

* 1991年: WWW 可能在 Internet 上利用
* 1994年: 标准化组织成立

### Hyper Text 历史 (P6)

* 1965年: 概念提出、Xanadu Model
* 1993年: 利用增加

### Internet 历史 (P7)

* 1969年: 原型 ARPANET 始动
* 1983年: 协议从 NCP 切换为 TCP/IP
* 1986年: backbone 移行至 NSFNet
* 1995年: 民间接管、个人用户利用增加

### WWW 和 Internet 区别 (P18)

* WWW: 通过 TCP/IP 协议、利用 HTTP 获取发送文章、图像、声音等方法
* Internet: 各个 local network 组成的全世界网络

### HTTP (P19)

* 应用层的协议
* 200: Ok
* 403: 禁止访问
* 404: 请求错误
* 500: 服务器错误

### Port 端口号 (P22)

* Service の特定: Ip + port
* 全知端口号
  * FTP: 20, 21
  * SSH: 22
  * SMTP: 25
  * WWW: 80
  * POP2/3: 109, 110
  * SSL: 443

### FTP (P23)

* 问题点
  * easy interface
  * 根据文件名进行获取发送
  * 没有检索功能
  * 基于性能

### Web Computing (P26)

* 1980 - `main frame`: 大型、集中处理

* 1990 - `client-server`: client 也搭载了处理机能、集中から分散へ

* 2000 - `network computing`: web application や www 环境利用

* 2010 - `cloud computing`: 只在需要的时候利用资源

* Web Application 或者 WWW 环境高度利用

### Web Application (P28)

* Web Brower 上で動作する、CGI、JS、PHP、C/S环境、e电商、online banking 留言板、SNS

* 静态 Page (P40)

* 动态 Page (P41): 
  
  - Web server 侧: CGI (Perl, PHP, Python, Ruby, 脚本), Servlet, JSP
  - Web client 侧: Applet, Flash, JS, Ajax
  - Web App Framework: 广范围、大规模、效率化、生产性向上
  - Web Server + DBMS + 脚本语言 (PHP)

### Web Service (P56)

使用 Internet 的标准技术、在网络上连接分布式的 Web Applicaion

* 提供数据作为 Web Service
* merit: 利用者增加、则产生利益 (P57)
  * 提供的服务向上（质量变好）
  * 形成利用者的氛围圈
  * 购买的人增加

### Mash Up (P61)

组合各种 Web serivce，形成一个 Application、可以减少成本

* merit
  * 开发的总成本削减
  * 有 idea 的话，可以很轻松得开始
  * 轻松增加删除功能
* demerit
  * 机能依存于 Web API。会受 API 的影响

### Web Service Architecture (P67)

* ROA 
  
  * 面向资源结构、2000年 roy fielding 提倡
  * REST (P69)
  * XML (P72): markup 语言、标签可以扩张自定义

* SOA
  
  * 面向服务结构、2004年 W3C 标准化团体提倡
  * SOAP (P74): XML format、可以使用包括 HTTP 以外的协议
  * WSDL
  * UDDI

* REST と SOAP の違い (P75)  
  REST: HTTP 上で気軽に利用できる  
  SOAP: Web Service の連携が強み
  
  |             | SOAP            | REST                |
  |:-----------:|:---------------:|:-------------------:|
  | 开发难度        | 难，需要一定环境进行测试    | 简单                  |
  | performance | 构文生成、解析为瓶颈，会有影响 | 少量数据交换速度很快，可以高效交换信息 |
  | 机能          | 高性能，可以处理复杂情况    | 依存 HTTP，不适合复杂场景     |

# 03 - 04 Web & 集合知

### 什么是集合知 (P2)

* 2004年 Surowiecki 发表、当初是集团的知性
* 2005年 O'Reilly 提倡 Web2.0、与 Web1.0 有 7 个不同的原则
* 典型实例 (P3): PageRank 算法 (Google 社) 

### 集合知发挥作用的条件 (P13)

* 多样性
  * それぞれに独自の視点を持って。探索空間が狭ければ、適切な解がないの可能
* 独立性
  * 他に影響を受けないよう、独自が確保されている
* 分散性
  * 去集中化。不抽象化问题，各个人基于自己能直接获得的信息进行判断
* 集约性
  * 基于以上三个条件，进行比较探讨
* 不是人越多越好
* 集団ゆえの危険性
  * Risk Shift: 偏向过激
  * Kossa Shift: 什么都不采用

### Web 2.0 的 7 原则 (P20)

* Web 作为 Platform
* 集合知的活用
* data 是驱动核心: database管理是中核能力
* 作为服务: software release cyle 结束
* 轻量化编程
* 不是一种设备的 software
* rich 的用户经验

### Search Engine (P28)

指定した Keyword を含む Document の一覧を出力する computer program

* 難しさ
  * data: 范围广、更新频繁、data数庞大、非结构化、形式不一
  * 利用者: query记述难、结果庞大

### 典型 Search Engine 的构成 (P38)

* Crawler (爬虫, P39): 自动下载 Web Page。Seed Page 集合作为起点、Queue 入队、出队、新的入队 
* Indexer (P40): 得到的数据整理保存到数据库中，添加 index 索引数据
* Query 处理 (P41): 处理用户的检索 Keyword，score ring 决定检索结果的排序

### <font color="red">PageRank (P44, 有计算)</font>

* 重要度的判定技术、重要的指标
* 优质的页面连接优质的界面、计算页面的重要度
* 不会影响页面的内容
* 在诞生前，主流是 category - directory 型检索 (P50)

### PageRank の Point (P48)

* 被连接数: 被连接数越多得分越高
* 引用该网页的元网页的得分会影响该网页
* 元网页的连接数越多，该网页的得分会变低

### SEO (P51)

搜索引擎优化，让某些结果处于上位

* 上位的 click 率、诱导率更大
* 企业 site 等
* 自己公司的产品

### PageRank merit (P52)

* 机械化生成，不容易受影响
* Page の内容は影響しない、検索式とは全く無関係、既に定まった量
* <font color="red">Page を text 解析はしなくて良い</font>
* 基本没有可以提高顺位的近道

### <font color="red">PageRank 计算 (P55)</font>

### Deep Web (P60)

* Search Engine access 不能 (可能: Surface Web)
* 针对利用者动态生成的页面
* 特殊形式的网页
* 脚本运行的网页
* 没有被连接的网页

### 大规模化 (P63)

* MapReduce の活用 (scale) (Hadoop)

### Personal化 (P65)

* 検索対象範囲
  * URL/Domain、分野限定、media限定、时间、区域、语言限定
* 検索処理内容
  * Keyword、检索model、ranking方法
* 検索結果表示
  * layout、件数、表示内容、传达方法...

# 05 - 06 Web Mining

### Big Data 分析 (P3)

* big data 特征
  * volume (大容量)
  * variety (多样性): 种类繁多
  * velocity (速度): 更新频率

### Web Mining (P4)

人的行动的 model 化，集合知的利用，新的价值

* Text Mining
* Graph Mining
* 机器学习

### Web Mining 手法 (P5)

* Web Contents Mining: 内容分析、`text mining`
* Web 构造 Mining: link关系、生成、消减、`graph mining`
* Web Log Mining: 行动log、历史记录、统计情报、`协调 filtering`

### Web Mining 的意义 (P12)

* これまでの社会調査を超えた分析が可能、膨大的数据
* Web Mining 并不能了解全世界、只有部分人用 Web、实社会的关系作用无法表现、实世界和 Web 有交集部分需要注意

### Text Mining (P14)

* 把 text 分成单词和 phase、统计出现频度和共起关系、定量解析数据
* 适用分野
  * CRM (P19): customer relation management 用户诉求、进行改良
  * 评价分析 (P18): blog、sns、bbs から評判情報を抽出かつ分析、そして改良
  * 特許情報 (P20): 专利文书分析、trend 和相互关系可视化
  * social network
  * 推荐系统...

### Text Mining の流れ (P21)

* 形态素解析 (P24): 最小的具有意义的单位、很容易出现错误结果
  * 同音异义语
  * 同形异义语
  * 表记ゆれ (拼写变体? 片假名?)
  * 暧昧性
* 不要语排除 (P30)
  * 不要语: 没用的词语
  * 用语: 内容语 (表示特定概念，需要)、机能语 (表示关系，不需要)

### <font color="red">文章同士の比較 (P31, 有计算)</font>

* TF (用语出现频度)
* IDF (逆文书频度)
* TF * IDF
* 类似度: 计算 cos(x, y)

### <font color="red">Clustering (P41, 有计算)</font>

无监督学习、无外部标准自动进行分类、data mining の一つの手法

* data mining
  * 相关 rule (无监督)
  * 回归分析 (有监督)
  * class 分类 (有监督)
  * clustering (无监督)
* cluster 手法的分类，从简单到复杂 (P44)
  * `阶层的 clustering`: 
    * <font color="red">`凝集型 clustering` (P45, 有计算)</font>: 最短距离、最长距离、群平均、Ward法...
      * Dendrogram 树形图，展示过程
      * 注意上面的方法只是用来更新距离。合并始终取距离（相似度）最近的点
    * `分割型阶层的 clustering`: k-means...
  * `分割最適化 clustering`: 函数最优化

# 07 - 08 複雑 Network

### Web Mining 手法 (P2)

* Web Contents Mining: 内容分析、`text mining`
* Web 构造 Mining: link关系、生成、消减、`graph mining`
* Web Log Mining: 行动log、历史记录、统计情报、`协调 filtering`

### Network 研究历史 (P13)

* ケーニヒスベルク問題 (P17)
  * 一笔画: 奇数个边的点，只能有 0 个或 2 个
* graph 理論 (P19)
* 1960年 random graph (P28)
  * 1959年提案 ER model
  * 两点间连线的概率为 p，p 小图疏，p 大图密
* 1967年 ミルグラムの実験 (P31)
* 1998年 small world (P35)
  * 现实世界的 small world 性
  * 平均距离小、有 cluster 性
  * 存在类似于 hub 的连接很多点的点，这个 small world 无法说明
* 1999年 scale free (P38)
  * 现实世界的 scale free 性、不均匀分布
  * hub 存在
  * べき法則
  * scale free network 满足 べき法則に分布

### <font color="red">Network 构造和指标 (P43, 有计算)</font>

* 次数分布 (P48)
* 平均经路长 (P49): 按照公式直接计算整体的平均经路长
* cluster 系数 (P50): 按照公式计算、表现网络的凝集性、系数越高关系密度越高
* 次数相关 (P53): 
  * +: 高次数更容易连接高次数
  * -: 高次数更容易连接低次数
* 中心性 (P55): 着目于单个点而非网络
  * 次数中心性: 次数
  * 近接中心性: 该点到其他点的路径长之和的平均值的倒数
  * 媒介中心性: 某两个点的所有路径中，必须经过该点的路径的比例、越高该点越重要

# <font color="red">09 - 10 协调 Filtering (协同过滤)</font>

### Web Mining 手法 (P3)

* Web Contents Mining: 内容分析、`text mining`
* Web 构造 Mining: link关系、生成、消减、`graph mining`
* Web Log Mining: 行动log、历史记录、统计情报、`协调 filtering`

### 推荐系统是什么 (P5)

* 迎合用户的喜好，提示推荐的 item
* 推荐后的效果: 用户发现喜好、网上商城盈利、CRM

### 推荐方法 (x5) (P13)

* 概要推荐: 新规和低频度
* 利用者评价
* 通知服务: 邮件通知，促进再次访问
* 关联item推荐
* 个性化: 利用行动历史、差异化

### 推荐利用目的 (x4) (P14)

从 `正确性` 到 `多样性`: 

* 备忘录
* 类似品
* 新规item
* 视野扩大

### 要素技术 (P15)

* human interface: 收集信息
* 机器学习、统计预测、情报检索: 预测、生成推荐信息
* database、并列计算、network: 信息处理。蓄积、处理、流通 (一一对应)

### 推荐历史 (P17)

* 1992年: 协调 filtering 的概念
* 1997年: Amazon 导入了 协调 filtering

### <font color="red">推荐系统的实行过程 (P20, 有计算, P28)</font>

  O-I-P: 

* 入力（嗜好数据）(P21)
  
  - `明示获得`
  - `暗暗获得`
  - 两者对比 (P22): 
    - data量: `暗暗获得` 更好
    - 评价正确性: `明示获得` 更好
    - 未评价未指示: `明示获得` 更好
    - 利用者认知: `明示获得` 更好

* <font color="red">嗜好预测 (P28, 有计算)</font>
  
  - `内容 base filtering`(P29): 基于 item 的内容特征（是否与用户符合）
  - `协调 filtering`(P30): 基于 user 的评价、行动记录
    - `item base 协调 filtering`(P31): item 之间的类似度
    - `user base 协调 filtering`(P39): user 之间、嗜好相似的用户
  - 两者对比 (P49): 
    - 多样性 (意外性): `协调 filtering` 更好
    - cold start (新用户、新产品): `内容 base filtering` 更好

* 出力（推荐系统）(P51)
  
  - `privacy问题`: 趣向、购买商品会话信息、个人身份识别信息、Ip、domain、P3P、privacy policy
  - `shilling attack (さくら攻撃)`
    - shilling bot: 伪评价
    - 目标 item
    - 攻击分类
      - push attack: 促进
      - nuke attack: 排除
      - 搅乱攻击: 推荐质量下降、降低系统信赖性
  - `人气偏见 (popularity bias) & 从众效应 (bandwagon effect)`
  - `filter bubble`: 会减少用户接触更多信息的机会
  - `推荐理由` 
  - `多样性`
  - `social 推荐`

# 11 - 12 Web Security

### Web 技術のおさらい（复习）

* `www`(P3): 地球规模的 hyper text、1989年提案、1991年实动、Tim Berners Lee
* `hyper text`(P4): 任意位置埋入 `hyper link`、1960年中顷、Ted Nelson、DMSの一つ
* `http`(P6): 
* `query文字列的危险性`(P13): 
  - 网络上流动: 被盗取、改写、用 https
  - 被记录在: web server, proxy server, firewall, brower cache
  - `使用 POST 而不是 GET`
* `Web Application`(P15): Web Brower 上で動作する、CGI、JS、PHP、C/S环境、e电商、online banking 留言板、SNS
* `静态 Page`(P17)
* `动态 Page`(P19): 
  - Web server 侧: CGI (Perl, PHP, Python, Ruby, 脚本), Servlet, JSP
  - Web client 侧: Applet, Flash, JS, Ajax
  - Web App Framework: 广范围、大规模、效率化、生产性向上
  - Web Server + DBMS + 脚本语言 (PHP)

### Web 认证

* `HTTP`(P29): 
  - state less, state full
  - 连接数有限、服务器增多同步成问题
* `Basic认证`(P33): 基于 HTTP 标准实装、用户名和密码、不是好的认证
  - 多用户使用同一个 brower
  - 无 logout
  - 基于 Base64，可以加密解密
* `Cookie管理和认证`(P36): 4KB程度的信息、KV键值对Set、服务器生成保存于客户端
  - 开发者侧: brower 可能拒绝 cookie
  - 利用者侧: 被盗取的风险
  - ThirdParty Cookie
  - Session 管理问题: URL里埋藏、form的Hidden领域埋藏（可以看源码找到）
  - 不要的服务的 Cookie 不用: 不给许可、删除 Cookie

### Web Application 的脆弱性和对策

* 通过参数推测可以看见其他文件 (P45)
* 用户输入格式问题 (P46)
  - 指定文字格式
  - sanitizing (无害化): 去除特殊符号 (`<` => `&lt;`)
  - 使用选择按钮、下拉菜单
* XSS 攻击 (P49): 执行了恶意脚本
* SQL Injection (P57): 对策: SQL语句预处理 (加入 `?` 占为符)
* CSRF (P63): 对策: 确认是否是利用者的意图

### その他 (P66)

* OS command injection (P67)
* session hijack (P68)
* directory traversal (P69)
* click jacking (P70)

# 13 Cloud Computing

### Cloud Computing is? (P2)

* 自らが保有するのではなく、cloud 事業者、network を越しに利用する service

### Cloud 登场背景 (P3)

* 1980 - `main frame`: 大型、集中处理
* 1990 - `client-server`: client 也搭载了处理机能、集中から分散へ
* 2000 - `network computing`: web application や www 环境利用
* 2010 - `cloud computing`: 只在需要的时候利用资源

### Cloud 普及背景 (P4)

* 技术进步: CPU高速化、虚拟化、移动设备低廉化、数据中心规模化
* cloud环境良好: 成本削减、灵活服务利用
* cloud经营者持续获得利润: 效率地提供资源

### Cloud 定义和特征 (P5 - 6)

* on-demand-self service: 响应式请求，用户也可以管理界面
* 大范围 internet-access: ネットにアクセスできる
* resource 共有: 多个用户共享
* 迅速な拡張性: 根据需要进行规模增加/削减
* 可计量服务: 利用した分だけ
* cloud service = service model * 利用 model

### Service Model (P7)

* SaaS (Software): 软件机能、只在需要的时候付钱，订阅制
* Paas (Platform): 开发环境
* Iaas (Infrastructure): 硬件资源、可添加或删除
  - hardware
  - server
  - storage
  - network

### 利用 Model (P12)

* public cloud: 公开
* private cloud: 企业内部
* community cloud: 多个企业内部
* hybrid cloud: 混合

### 导入 Cloud 的优点 (P13)

* 外的 merit
* 战略的 merit
* cost 的 merit
* 人的 merit

### Cloud 提供的服务 (P16)

* `虚拟 server`: 物理环境下、论理的分成多个虚拟环境
* `storage service`: archieve、backup、file server 利用
* `network service`: 构筑专用网、专用线、访问公司内服务
* `database service`: RDBMS、datawareouts（资源仓储）、NoSQL
* `data 分析 service`: AWS、Azure、GCP
* `AI / Machine Learning service`: 用户自己学习、预先提供大量数据

### Cloud Service 的 4 个 Pattern (P30)

* `B2C分野`: 商业 -> 个人
* `公共分野`: 政府
* `企业分野`: enterprise
* `新事业分野`: 人工智能、大数据

### Cloud 活用 (P31)

* `CDN`: 内容分发网络
* `app开发、test环境`: 
* `制造业`: 业务效率化、成本削减、远距离保存数据
* `地方政府`: 
* `Big Data`: 

# 14 Access 解析 & Internet 广告

### Access 解析 (P2)

### Access 解析结果的应用 (P3)

* Web site 改善分析
* Internet 广告的投资最优化
* 利用者的嗜好分析
* 优良顾客分析
* user segmentation

### Access Log 解析的指标 (P6)

* page view (PV)
  * 每一次的页面请求
* unique user (UU)
  * 一定时间内，同一个人，多次访问算一次人数
* session 数 (P8)
  * 同一个人，一定时间过后，被认为是新的对话
* 滞留时间 (P9)
  * 访问一次的时长 (就算时间长，也不能说重要)
* click 率 (P9)
  * (点击总数) / (包含广告连接的总数)

### 同一个人的判定 (P10)

* 很难。现实中使用 IP、user-agent。
* User-Agent (P10): 包含了用户浏览器、OS 等信息

### Access 解析方法 (P12)

* server log 解析型 (日志, P13)
* packet capture 解析型 (抓包, P16)
  * switch, hub
  * real-time 解析可能
* tag 插入型 (页面脚本, P17)
  * JS 脚本运行，发送数据到服务器

### Access 解析的難しさ (P19)

* crawler 爬虫影响
  * (x) server log 解析型 & packet capture 解析型
* brower's return button
  * (x) server log 解析型 & packet capture 解析型
* pdf etc non-html pages
  * (x) tag 插入型
* Bugs
  * (x) tag 插入型

### Internet 广告 (P20)

与电视广告、新闻广告等相比，Internet 广告投资效益更优。(P22)

* cyber communication (P29)
* digital advertising consortium (P29)
* cyber agent (P29)

### Internet 广告的历史 (P30)

* 1995 ~ 2000
  
  * banner 广告 (P31, 图片广告)
  * mail 广告 (P32)

* 2000 ~ 2005
  
  * affiliate 广告 (P33, 支付一定比例的报酬)
  * 检索运动型广告 (P35, 根据检索内容)
    * step1: 选定人气高的 Keyword
    * step2: Keyword auction
    * step3: 广告表示
  * contents 运动型广告 (P40, 跟网页内容相关度高)

* 2005 ~ 2010
  
  * 行动 targeting (P42, 根据浏览内容历史)

* 2010 ~ 2015
  
  * 興味関心運動型広告 (P44)
  * ad network 广告 (P45, 广告网络)
  * adexchange (P47, 广告交易平台)
  * native 广告 (P48, 很自然融入的广告)

### Internet 广告的特征 (P50)

* interactive (交互性): 能動的に行うことが可能
* targeting (目标性): 容易针对特定目标
* 效果测定: 容易测定效果

### Internet 广告的课题 (P51)

* 信頼性
* domain 竞争、买卖
* 应对不同环境和设备
* privacy、个人信息收集