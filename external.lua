package("librnd")
    set_description("The librnd package")

    add_urls("https://github.com/Xyfuture/librnd.git")
    add_versions("1.0", "2626825")

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)


package("libprim")
    set_kind("library", {headeronly = true})
    set_description("The libprim package")

    add_urls("https://github.com/Xyfuture/libprim.git")
    add_versions("1.0", "07b3593")

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)
-- end
