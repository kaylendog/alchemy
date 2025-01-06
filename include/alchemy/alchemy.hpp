#pragma once

/// @file A unified header for the Alchemy engine.

#include <alchemy/asset/asset.hpp>
#include <alchemy/asset/loader.hpp>
#include <alchemy/asset/manager.hpp>
#include <alchemy/asset/texture.hpp>

#include <alchemy/async/mutex.hpp>
#include <alchemy/async/pool.hpp>

#include <alchemy/ecs/component.hpp>
#include <alchemy/ecs/entity.hpp>
#include <alchemy/ecs/schedule.hpp>
#include <alchemy/ecs/system.hpp>
#include <alchemy/ecs/world.hpp>

#include <alchemy/render/mesh.hpp>
#include <alchemy/render/primitive.hpp>

#include <alchemy/util/btree.hpp>
#include <alchemy/util/result.hpp>
