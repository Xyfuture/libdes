includes("external.lua")
set_policy("package.include_external_headers", false)

add_requires("libprim main",{debug=true})
add_requires("librnd main",{debug=true})
add_requires("zlib 1.2.12",{debug=true})

add_rules("mode.debug","mode.release")
set_config("toolchain","gcc")


target("libdes")
    set_kind("static")
    add_files("src/**.cc|**_TEST.cc")
    -- add_installfiles("src/(**.h)",{prefixdir="include/des/"})
    add_headerfiles("src/(**.h)")
    add_includedirs("src/",{public=true})
    add_packages("libprim")
    add_packages("librnd")
    add_packages("zlib")
