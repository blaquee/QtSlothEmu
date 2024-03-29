#-------------------------------------------------
#
# Project created by QtCreator 2017-09-11T00:12:28
#
#-------------------------------------------------



CONFIG(debug, debug|release) {
    DIR_SUFFIX = d
} else {
    DIR_SUFFIX =
}

!contains(QMAKE_HOST.arch, x86_64) {
    X64_BIN_DIR = ./bin/x32$${DIR_SUFFIX}         # Relative BIN path, 32-bit
    X64_GEN_DIR = ./gui_build/out32$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
} else {
    X64_BIN_DIR = ./bin/x64$${DIR_SUFFIX}         # Relative BIN path, 64-bit
    X64_GEN_DIR = ./gui_build/out64$${DIR_SUFFIX} # QMake temporary generated files, placed inside the build folder. (OBJ, UI, MOC)
}


##
## QMake output directories
##
DESTDIR = $${X64_BIN_DIR}


QT       += core gui widgets
# greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#generate debug symbols in release mode
QMAKE_CFLAGS_RELEASE += -Zi
QMAKE_LFLAGS_RELEASE += /DEBUG

# http://www.hexblog.com/?p=991
QMAKE_CXXFLAGS += -DQT_NO_UNICODE_LITERAL


TARGET = QtWidget
TEMPLATE = lib
LIBS += -luser32 -lshlwapi

!contains(QMAKE_HOST.arch, x86_64) {
    LIBS += -lx32dbg -lx32bridge -L"$$PWD/pluginsdk"
} else {
    LIBS += -lx64dbg -lx64bridge -L"$$PWD/pluginsdk"
}


SOURCES +=\
        mainwindow.cpp \
    contextview.cpp \
    cpumodel.cpp \
    qemuplugin.cpp \
    pluginmain.cpp

HEADERS  += mainwindow.h \
    contextview.h \
    cpumodel.h \
    defines.h \
    qemuplugin.h \
    pluginmain.h \
    pluginsdk/capstone/arm.h \
    pluginsdk/capstone/arm64.h \
    pluginsdk/capstone/capstone.h \
    pluginsdk/capstone/m68k.h \
    pluginsdk/capstone/mips.h \
    pluginsdk/capstone/platform.h \
    pluginsdk/capstone/ppc.h \
    pluginsdk/capstone/sparc.h \
    pluginsdk/capstone/systemz.h \
    pluginsdk/capstone/x86.h \
    pluginsdk/capstone/xcore.h \
    pluginsdk/dbghelp/dbghelp.h \
    pluginsdk/DeviceNameResolver/DeviceNameResolver.h \
    pluginsdk/jansson/jansson.h \
    pluginsdk/jansson/jansson_config.h \
    pluginsdk/jansson/jansson_x64dbg.h \
    pluginsdk/lz4/lz4.h \
    pluginsdk/lz4/lz4file.h \
    pluginsdk/lz4/lz4hc.h \
    pluginsdk/TitanEngine/TitanEngine.h \
    pluginsdk/XEDParse/XEDParse.h \
    pluginsdk/yara/yara/ahocorasick.h \
    pluginsdk/yara/yara/arena.h \
    pluginsdk/yara/yara/atoms.h \
    pluginsdk/yara/yara/compiler.h \
    pluginsdk/yara/yara/dotnet.h \
    pluginsdk/yara/yara/elf.h \
    pluginsdk/yara/yara/endian.h \
    pluginsdk/yara/yara/error.h \
    pluginsdk/yara/yara/exec.h \
    pluginsdk/yara/yara/exefiles.h \
    pluginsdk/yara/yara/filemap.h \
    pluginsdk/yara/yara/globals.h \
    pluginsdk/yara/yara/hash.h \
    pluginsdk/yara/yara/hex_lexer.h \
    pluginsdk/yara/yara/integers.h \
    pluginsdk/yara/yara/lexer.h \
    pluginsdk/yara/yara/libyara.h \
    pluginsdk/yara/yara/limits.h \
    pluginsdk/yara/yara/mem.h \
    pluginsdk/yara/yara/modules.h \
    pluginsdk/yara/yara/object.h \
    pluginsdk/yara/yara/parser.h \
    pluginsdk/yara/yara/pe.h \
    pluginsdk/yara/yara/pe_utils.h \
    pluginsdk/yara/yara/proc.h \
    pluginsdk/yara/yara/re.h \
    pluginsdk/yara/yara/re_lexer.h \
    pluginsdk/yara/yara/rules.h \
    pluginsdk/yara/yara/scan.h \
    pluginsdk/yara/yara/sizedstr.h \
    pluginsdk/yara/yara/stream.h \
    pluginsdk/yara/yara/strutils.h \
    pluginsdk/yara/yara/threading.h \
    pluginsdk/yara/yara/types.h \
    pluginsdk/yara/yara/utils.h \
    pluginsdk/yara/yara.h \
    pluginsdk/_dbgfunctions.h \
    pluginsdk/_plugin_types.h \
    pluginsdk/_plugins.h \
    pluginsdk/_scriptapi.h \
    pluginsdk/_scriptapi_argument.h \
    pluginsdk/_scriptapi_assembler.h \
    pluginsdk/_scriptapi_bookmark.h \
    pluginsdk/_scriptapi_comment.h \
    pluginsdk/_scriptapi_debug.h \
    pluginsdk/_scriptapi_flag.h \
    pluginsdk/_scriptapi_function.h \
    pluginsdk/_scriptapi_gui.h \
    pluginsdk/_scriptapi_label.h \
    pluginsdk/_scriptapi_memory.h \
    pluginsdk/_scriptapi_misc.h \
    pluginsdk/_scriptapi_module.h \
    pluginsdk/_scriptapi_pattern.h \
    pluginsdk/_scriptapi_register.h \
    pluginsdk/_scriptapi_stack.h \
    pluginsdk/_scriptapi_symbol.h \
    pluginsdk/bridgegraph.h \
    pluginsdk/bridgelist.h \
    pluginsdk/bridgemain.h

FORMS    += mainwindow.ui \
    contextview.ui

#DISTFILES += \
#    pluginsdk/capstone/capstone_x64.lib \
#    pluginsdk/capstone/capstone_x86.lib \
#    pluginsdk/dbghelp/dbghelp_x64.a \
#    pluginsdk/dbghelp/dbghelp_x64.lib \
#    pluginsdk/dbghelp/dbghelp_x86.a \
#    pluginsdk/dbghelp/dbghelp_x86.lib \
#    pluginsdk/DeviceNameResolver/DeviceNameResolver_x64.a \
#    pluginsdk/DeviceNameResolver/DeviceNameResolver_x64.lib \
#    pluginsdk/DeviceNameResolver/DeviceNameResolver_x86.a \
#    pluginsdk/DeviceNameResolver/DeviceNameResolver_x86.lib \
#    pluginsdk/jansson/jansson_x64.a \
#    pluginsdk/jansson/jansson_x64.lib \
#    pluginsdk/jansson/jansson_x86.a \
#    pluginsdk/jansson/jansson_x86.lib \
#    pluginsdk/lz4/lz4_x64.a \
#    pluginsdk/lz4/lz4_x64.lib \
#    pluginsdk/lz4/lz4_x86.a \
#    pluginsdk/lz4/lz4_x86.lib \
#    pluginsdk/TitanEngine/TitanEngine_x64.a \
#    pluginsdk/TitanEngine/TitanEngine_x64.lib \
#    pluginsdk/TitanEngine/TitanEngine_x86.a \
#    pluginsdk/TitanEngine/TitanEngine_x86.lib \
#    pluginsdk/XEDParse/XEDParse_x64.a \
#    pluginsdk/XEDParse/XEDParse_x64.lib \
#    pluginsdk/XEDParse/XEDParse_x86.a \
#    pluginsdk/XEDParse/XEDParse_x86.lib \
#    pluginsdk/yara/yara_x64.lib \
#    pluginsdk/yara/yara_x86.lib \
#    pluginsdk/x32bridge.lib \
#    pluginsdk/x32dbg.lib \
#    pluginsdk/x64bridge.lib \
#    pluginsdk/x64dbg.lib
