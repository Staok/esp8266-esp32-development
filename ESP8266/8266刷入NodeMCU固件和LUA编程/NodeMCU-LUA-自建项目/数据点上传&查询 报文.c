目标IP  api.heclouds.com 或者 183.230.40.33  端口80   TCP

注意 Length是BODY字节数 写的不对上传就失败！
---------------------
POST http://api.heclouds.com/devices/17178261/datapoints?type=3 HTTP/1.1
api-key: UD9XFajDKEqGn1HQGHY9b2D8KZg=
Host: api.heclouds.com
Content-Length: 10

{"line":3}
---------------------
另一个例子

POST http://api.heclouds.com/devices/19891499/datapoints?type=3 HTTP/1.1
api-key: UD9XFajDKEqGn1HQGHY9b2D8KZg=
Host: api.heclouds.com
Content-Length: 80

{"A_temperature":36.5,"A_pulse":71,"A_bloodpressure":122,"A_bloodpressure_s":82}
-------------------------------------
多个数据流上传：
{"line":3,"数据流名称":3}


详见 https://open.iot.10086.cn/doc/art260.html#68

        URL：//api.heclouds.com/devices/2214570/datapoints?type=3

        示例：{"temperature":22.5,"humidity":"95.2%"}

        表示在数据流temperature中增加一个数据点22.5，在humidity中增加一个数据点95.2%。

        URL：//api.heclouds.com/devices/2214570/datapoints?type=4

        示例：{"temperature":{"2015-03-22T22:31:12":22.5}}

        表示在数据流temperature中加一个数据点，在2015年3月22日22点31分12秒的值为22.5

        URL：//api.heclouds.com/devices/2214570/datapoints?type=5

        示例：,;temperature,2015-03-22T22:31:12,22.5;pm2.5,89

        表示在数据流temperature中加一个数据点，即2015年3月22日22点31分12秒的值为22.5；
		在数据流pm2.5中添加一个数据点，即当前时间的值为89。
		
		
	

查询数据流信息：	                                           数据流名称   获取最近5个数据   最后要加个回车
-----------------------
GET http://api.heclouds.com/devices/17178261/datapoints?datastream_id=line&limit=5 HTTP/1.1
api-key: UD9XFajDKEqGn1HQGHY9b2D8KZg=
Host: api.heclouds.com

----------------------
	



	
		
		
几个月前产生的一个新型封闭区域（如学校、小区等）的快速递物无人机开发，它通过app下达出发点和目标点以及要运输物品重量、支付金额等信息，在原地等待无人机到来，通过让无人机扫描手机上的二维码确定下单者是本人，然后无人机便可携带包装好的运输物品通过高空自动巡航到达目的地并投放，整个自动巡航过程，无人机会实时通过onenet云上传机体信息和坐标、气温、风力等信息，以实现云监控，一旦遇到危险状况便可以通过onenet云应用人工控制安全降落地面，项目还包含许多细节这里不一一展开，在学校里，这个项目被评为大创省级项目，本人今年大三，曾经获智能车竞赛国一、节能减排国一和全国电子设计大赛省一等优异奖项，有一定的软硬件实力和测试能力，很希望能获得一块onenet测试版进行项目推进和测试。

一个封闭区域（如学校、小区等）的新型快速递物无人机开发，下单后无人机携带包装好的运输物品通过高空自动巡航到达目的地并投放，自动巡航过程中无人机会实时在onenet云上传机体信息和坐标、气温、风力等信息以实现云监控，一旦遇到危险状况便通过onenet云应用人工控制安全降落地面，这个项目被评为大创省级项目，本人今年大三，曾经获智能车竞赛国一、节能减排国一和全国电子设计大赛省一等优异奖项，有一定的软硬件实力和测试能力，很希望能获得一块onenet测试版进行项目推进和测试。