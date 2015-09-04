### ArduCom - Arduino Communication Shield

Uygulama notlarını ve kodlarını bu sayfada bulacaksınız. 


![](https://camo.githubusercontent.com/ba5fcf3d3f206b85e9e18cdf34eedb6bf2711597/68747470733a2f2f74696e796a70672e636f6d2f736974652f6f75747075742f66747365686d756668316d316d626a642e706e672f61726475436f6d2e706e67)


Projelerinizde kablosuz haberleşme uygulamaları yapmanız için 2.4GHz’lık haberleşme modülleri ile açık alanda 250 metreye kadar iletişim sağlayabilirsiniz.

Arduino Communication Shield kablosuz haberleşme modülü, SD kart ve I2C haberleşme pinleri çeşitli sensörlerin bağlanabildiği geliştirme kartıdır. Arduino UNO ile uyumludur.

Aynı zamanda birden fazla noktaya data gönderebilir ve kendi aralarında bir network oluşturabilirsiniz. USB den bilgisayara bağlı olan ArduCom’a kablosuz olarak gelen verileri bilgisayara aktara bilirken bilgisayardan da bilgi gönderebilirsiniz.

Üzerinde bulunan MicroSD kart soketi ile bilgi kaydı ve bilgi okuma işlemleri yapabilirsiniz. I2C bağlantı pinleri ile bu protokolü kullanan çeşitli sensörlerin bağlantısını kolayca yapabilirsiniz ve birden fazla sensörün bağlantısını yapabilirsiniz.

Kullanım alanları ve Örnek projeler: *Kablosuz haberleşme projeleri ( 0-250 Metre ) *Birden fazla ArduCom Shield kullanarak Network oluşturma *Bilgisayardan kablosuz olarak data gönderme *10DoF IMU ile 3 eksen ivme, 3 eksen açısal ivme, Yükseklik, Sıcaklık bilgisi kayıt etme, kablosuz olarak gönderme

Uygulamalar : 

* Farklı noktalardan dataları kayıt altına almak
* Nesnelerin İnterneti ( IoT ) projeleri
* Datalogger olarak kullanımı
* Uzaktan kontrollü robot
* Yüksek İrtifa Balon ile iletişim denemeleri
* Model Uydu Projeleri

Teknik Detay:

* Arduino UNO ile uyumlu
* Dahili NRF24l01
* Tüm MicroSD kartlar ile uyumlu çalışmaktadır.(Tercihen Class10)
* Tüm I2C Sensörlerinin bağlantılarına uygun


Arduino Pini	Kullanımı

Dijital Pinleri
* D0	Boş
* D1	Boş
* D2	Boş
* D3	Boş
* D4	Boş
* D5	Programlanabilir LED
* D6	CS /SD Kart
* D7	CSN / NRF
* D8	CE / SPI
* D9	Boş
* D10	Boş
* D11	MOSI / SPI
* D12	MISO / SPI
* D13	SCK

Analog Pinleri
* A0	Trimpot veya Boş *
* A1	Trimpot veya Boş *
* A2	Boş
* A3	Boş
* A4	SDA
* A5	SCL
