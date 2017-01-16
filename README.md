
	EGYM demo 1 task 2 by Djeradi Djibril 2017


	this is a 64 bit demo

	Requirements:
	=============

	- minimum 1366 x 800 screen resolution ( better a full HD monitor )
	- up to date GPU drivers capable of OpenGL 2.0 & non power of 2 texturing ( NVIDIA or ATI )
	- QT Creator 4.2.0
	- QT 5.7.1 framework
	- Windows 8.1 x64
	- Visual Studio 2015 community ( compiler )
	- In case you need to run the app without building it you need Visual C++ Redistributable for Visual Studio 2015 
	( https://www.microsoft.com/en-us/download/details.aspx?id=48145 )
	vc_redist.x64.exe


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


	How To Use the app:
	===================

	F1 key shows / hides the hardware controls
	the scroller controls the ball Y value


	Tested on:
	==========

	Windows 8.1 64 bit
	NVIDIA GeForce 210
	NVIDIA 620M
	NVIDIA 720M 
