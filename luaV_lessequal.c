
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

extern int LEnum (const TValue *, const TValue *);
extern int lessequalothers (lua_State *, const TValue *, const TValue *);

int luaV_lessequal (lua_State *L, const TValue *l, const TValue *r) {
  if ((((((((l))->tt_)) & 0x0F)) == (3)) && (((((((r))->tt_)) & 0x0F)) == (3)))
    return LEnum(l, r);
  else return lessequalothers(L, l, r);
}

