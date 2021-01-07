
#include <time.h>
#include <setjmp.h>
#include <ctype.h>

#include "lapi.h"
#include "lauxlib.h"
#include "lcode.h"
#include "lctype.h"
#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "llex.h"
#include "llimits.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lopnames.h"
#include "lparser.h"
#include "lprefix.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "luaconf.h"
#include "lua.h"
#include "lualib.h"
#include "lundump.h"
#include "lvm.h"
#include "lzio.h"



extern int luaK_codek(FuncState *, int, int);
extern int luaK_numberK(FuncState *, lua_Number);
extern int luaK_codeAsBx(FuncState *, OpCode, int, int);
extern int fitsBx(lua_Integer);
extern int luaV_flttointeger(lua_Number, lua_Integer *, F2Imod);

static void luaK_float (FuncState *fs, int reg, lua_Number f) {
  lua_Integer fi;
  if (luaV_flttointeger(f, &fi, F2Ieq) && fitsBx(fi))
    luaK_codeAsBx(fs, OP_LOADF, reg, ((int)((fi))));
  else
    luaK_codek(fs, reg, luaK_numberK(fs, f));
}