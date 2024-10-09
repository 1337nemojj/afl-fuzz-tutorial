cmake_minimum_required(VERSION 3.5)

project(QtApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
	    main.cpp
	        mainwindow.cpp
		)

	set(HEADERS
		    mainwindow.h
		    )

	    set(UIS
		        mainwindow.ui
			)

		qt5_wrap_ui(UI_HEADERS ${UIS})
		qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

		add_executable(QtApp ${SOURCES} ${HEADERS} ${UI_HEADERS} ${MOC_SOURCES})

		target_link_libraries(QtApp Qt5::Widgets)
