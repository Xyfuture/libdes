includes("external.lua")
add_requires("libprim")
add_requires("librnd")
add_requires("zlib 1.2.12")


set_config("toolchain","gcc")


target("libdes")
    set_kind("static")
    add_files("src/**.cc|**_TEST.cc")
    add_installfiles("src/**.h",{prefixdir="include/des/"})
    add_includedirs("src/",{public=true})
    add_packages("libprim")
    add_packages("librnd")
    add_packages("zlib")