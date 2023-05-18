USE dlut;
-- 用户基本信息表(uid,username,userpass,uptime)
DROP TABLE IF EXISTS USER;
CREATE TABLE IF NOT EXISTS USER(
    uid INTEGER NOT NULL AUTO_INCREMENT COMMENT '用户唯一id',
    username VARCHAR(16) UNIQUE NOT NULL COMMENT '用户名',
    userpass CHAR(168) NOT NULL COMMENT '密码',
    uptime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NOT NULL COMMENT '更新时间',
    PRIMARY KEY `userpri` (`uid`)
)AUTO_INCREMENT 10000;

INSERT INTO USER (username, userpass) VALUES ('zs','123'),
                                             ('ls','456')
                                             ;
-- 标明字段插入,部分数据库的版本，对于默认为 0 的值 报错

-- 字符串使用  ' '  ,  数据库组件     `user`
-- 密码都会加密存储CSDN，携程，单向散列函数加密
-- MD5 128      SHA  168，产生的摘要的长度定长
-- 选项
--       默认值选项,适合于系统统计功能字段
--       是否为空[默认情况可以为NULL]，NULL 不能用在主码上， 【错误】NULL==NULL 【FALSE】  ，isNull判断
--       自动增长
-- 约束
--   主键约束:  唯一的标识元组，不能为NULL
--   外键约束    引用到其他关系上的主键
--   唯一约束： 唯一的标识元组  ，可以为NULL



-- 用户扩展信息表(eid,phone,address,uid,uptime)
DROP TABLE IF EXISTS extra;
CREATE TABLE IF NOT EXISTS extra(
    eid INTEGER NOT NULL AUTO_INCREMENT COMMENT '信息id',
    phone CHAR(17) UNIQUE COMMENT '电话号码',
    address VARCHAR(50) COMMENT '送货地址',
    uid INTEGER COMMENT '关联的用户',
    uptime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '更新时间',
    PRIMARY KEY `extrapri` (`eid`),
    CONSTRAINT FOREIGN KEY `ex_uid_to_u_uid` (`uid`) REFERENCES `user`(`uid`)
) CHARSET utf8;
-- 商家信息(bid,bname,bdes,uptime)
DROP TABLE IF EXISTS merchant ;
CREATE TABLE IF NOT EXISTS merchant(
    bid INTEGER NOT NULL AUTO_INCREMENT COMMENT '商家唯一id',
    bname VARCHAR(16) UNIQUE NOT NULL COMMENT '商家名',
    bdes CHAR(168) NOT NULL COMMENT '商家描述',
    uptime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NOT NULL COMMENT '更新时间',
    PRIMARY KEY `merchantpri` (`bid`)
)AUTO_INCREMENT 10000;

INSERT INTO merchant (bname, bdes) VALUES ('zhang','一个姓张的商家'),
                                             ('li','一个姓李的商家')
                                             ;
-- 商品信息(gid,gname,gdes,bid,uptime)
DROP TABLE IF EXISTS goods ;
CREATE TABLE IF NOT EXISTS product(
    gid INTEGER NOT NULL AUTO_INCREMENT COMMENT '商品唯一id',
    gname VARCHAR(16) UNIQUE NOT NULL COMMENT '商品名',
    gdes CHAR(168) NOT NULL COMMENT '商品描述',
    bid INTEGER NOT NULL AUTO_INCREMENT COMMENT '商家唯一id',
    uptime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NOT NULL COMMENT '更新时间',
    PRIMARY KEY `goodspri` (`gid`)
)AUTO_INCREMENT 10000;

INSERT INTO merchant (gname, gdes) VALUES ('ipad','好用的平板'),
                                             ('iphone','好用的手机')
                                             ;
-- 订单信息(oid,uid,gid,uptime)
DROP TABLE IF EXISTS ORDER ;
CREATE TABLE IF NOT EXISTS ORDER(
    oid INTEGER NOT NULL AUTO_INCREMENT COMMENT '订单唯一id',
    uid INTEGER NOT NULL AUTO_INCREMENT COMMENT '用户唯一id',
    gid INTEGER NOT NULL AUTO_INCREMENT COMMENT '商品唯一id',
    uptime TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP NOT NULL COMMENT '更新时间',
    PRIMARY KEY `orderpri` (`oid`)
)AUTO_INCREMENT 10000;

INSERT INTO merchant (uid,gid) VALUES ('1','2'),
                                             ('3','4')
                                             ;
