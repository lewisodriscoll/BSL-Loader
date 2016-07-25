cl /LD bsl_loader.c /link /DEF:bsl_loader.def
cl try_loader.c /link bsl_loader.lib
