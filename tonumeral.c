
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




static int tonumeral (const expdesc *e, TValue *v) {
  if (((e)->t != (e)->f))
    return 0;
  switch (e->k) {
    case VKINT:
      if (v) { TValue *io=(v); ((io)->value_).i=(e->u.ival); ((io)->tt_=(((3) | ((0) << 4)))); };
      return 1;
    case VKFLT:
      if (v) { TValue *io=(v); ((io)->value_).n=(e->u.nval); ((io)->tt_=(((3) | ((1) << 4)))); };
      return 1;
    default: return 0;
  }
}