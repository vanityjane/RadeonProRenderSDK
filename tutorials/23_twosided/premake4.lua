project "23_twosided"
    kind "ConsoleApp"
    location "../build"
    files { "../23_twosided/**.h", "../23_twosided/**.cpp"}
    files { "../common/common.cpp","../common/common.h"} 

    -- remove filters for Visual Studio
    vpaths { [""] = { "../23_twosided/**.h", "../23_twosided/**.cpp","../common/common.cpp","../common/common.h"} }

    includedirs{ "../../RadeonProRender/inc" } 
    
    buildoptions "-std=c++11"


	if os.istarget("linux") then
	    linkoptions {"-pthread"}
    end

	links {"RadeonProRender64"}
    filter "configurations:Debug"
        targetdir "../Bin"
    filter "configurations:Release"
        targetdir "../Bin"
    filter {}
    
