from conans import ConanFile, tools

class devel(ConanFile):

    name = "devel"

    version = "7.0"

    settings = "os", "compiler", "build_type", "arch"

    requires = "libs/7.0@user/stable","hdr-pkg/7.0@user/devel","qt/5.15.2", "sqlite3/3.36.0"