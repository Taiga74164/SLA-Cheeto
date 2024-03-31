#pragma once

#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

#include "appdata/helpers.h"
#include "magic_enum.hpp"
#include "cheat/vars.h"

#include "events/event.hpp"
#include "events/handlers/methodeventhandler.hpp"
#include "events/handlers/functoreventhandler.hpp"
#include "events/joins/handlereventjoin.hpp"
#include "events/joins/eventjoinwrapper.hpp"