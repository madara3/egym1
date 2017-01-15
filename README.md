
	EGYM demo 1 task 2 by Djeradi Djibril 2017


	this is a 64 bit demo

	Requirements:
	=============

	- QT Creator 4.2.0
	- QT 5.7.1 framework
	- Windows 8.1 x64
	- Visual Studio 2015 community ( compiler )
	- In case you need to run the app without building it you need Visual C++ Redistributable for Visual Studio 2015 ( https://www.microsoft.com/en-us/download/details.aspx?id=48145 )


	Folders:
	========
	
	debug - contains debug build of the demo + required debug dlls
	release - contains release build of the demo + required dlls
	res - contains resources used by the app


	How to build:
	=============
	
	open egym.pro in QT Creator
	configure the project in settings 
	    - disable shadow build
	    - choose Deskto QT 5.7.1 MSVC2015_64bit   
	clean project then run QMake and build
