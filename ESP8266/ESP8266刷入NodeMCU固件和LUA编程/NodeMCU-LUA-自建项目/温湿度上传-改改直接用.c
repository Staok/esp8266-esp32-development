    --init.lua
    --led blink
    lighton=0
    pin_led=4
    gpio.mode(pin_led,gpio.OUTPUT)
    tmr.alarm(0,500,1,function()
		if lighton==0 then
			lighton=1
			gpio.write(pin_led,gpio.HIGH)
		else
			lighton=0
			gpio.write(pin_led,gpio.LOW)
		end
    end)
    --WIFI connect
    print("set up wifi mode")
    wifi.setmode(wifi.STATION)
    wifi.sta.config("360","12345678") --连接WIFI热点，两个参数分别表示SSID 和 密码
    wifi.sta.connect()
    wifi.sta.autoconnect(1) --使能自动连接
    --每秒中去检查一次连接情况
    wifi_connetion=0
    tmr.alarm(1, 1000, 1, function()
		if wifi.sta.getip()== nil then
			if wifi_connetion == 1 then
				print("IP unavaiable,maybe wifi disappeared, Waiting...")
				wifi_connetion = 0
			else
				print(" Waiting for connecting...")
			end
		else
			if wifi_connetion == 0 then
				print("Config done, IP is "..wifi.sta.getip())
				wifi_connetion = 1
			end
		end
    end)
    --每10秒钟上传一次温湿度信息到OneNET
    temp = 0
    hum = 0
    tmr.alarm(2, 10000, 1, function()
    --if wifi connected, send HTTP data with type 5
		if wifi_connetion == 1 then
			dofile("dht11_.lua") --通过dht11_.lua脚本获取传感器信息
			str=",;humidity,"..hum..";temperature,"..temp --格式5，详情参见HTTP协议文档
			print(str.." len: "..string.len(str))
			
			sk=net.createConnection(net.TCP, 0) --normal link
			sk:on("receive", function(sck, c) print(c) end ) --收到了数据立即打印
			sk:on("disconnection", function() print("tcp:disconnection") end ) --失去连接则打印信息
			sk:connect(80,"183.230.40.33") --与OneNET建立TCP连接
			-- Wait for connection before sending.
			--使用HTTP协议，采用type=5的格式，上传数据
			sk:on("connection", function(sck,c)
			print("tcp:connection")
			--HTTP 1.0: socket closed right after communication
			--type=5 format: ,;xxx,x;xxx,x
			sk:send(
			"POST /devices/599019/datapoints?type=5 HTTP/1.0\r\n"
			.."api-key: 60ejo9FrV2328GndsKbQvPURzfYA\r\n"
			.."Host: api.heclouds.com\r\n"
			.."Content-Length: "..string.len(str).."\r\n\r\n"
			..str.."\r\n\r\n")
			end)
		end
    end)