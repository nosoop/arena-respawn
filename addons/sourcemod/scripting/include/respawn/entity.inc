/**
 * Copyright © 2014 Win/Lose/Continue
 *
 * This file is part of ARENA: RESPAWN.
 *
 * ARENA: RESPAWN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ARENA: RESPAWN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with ARENA: RESPAWN.  If not, see <http://www.gnu.org/licenses/>.
 */

#if defined _respawn_include_entity
  #endinput
#endif
#define _respawn_include_entity

/**
 * Sets an entity's internal keyvalue.
 *
 * @param entity           Entity index.
 * @param key
 * @param value
 * @return                 True if successful, otherwise false.
 */
stock Entity_SetKeyValue(entity, const String:key[], value) {

  new String:output[64];
  Format(output, sizeof(output), "%s %d", key, value);
  return Entity_AddOutput(entity, output);

}

/**
 * Sets an entity's internal keyvalue.
 *
 * @param entity           Entity index.
 * @param key
 * @param value
 * @return                 True if successful, otherwise false.
 */
stock Entity_SetKeyValueFloat(entity, const String:key[], Float:value) {

  new String:output[64];
  Format(output, sizeof(output), "%s %f", key, value);
  return Entity_AddOutput(entity, output);

}

/**
 * Finds the origin of an entity relative to the world.
 * Contrast with smlib's Entity_GetAbsOrigin, which only finds the origin relative to the entity's parent.
 *
 * @param entity           Entity index.
 * @param vector           3 dimensional vector array.
 * @noreturn
 */
stock Entity_GetTrueAbsOrigin(entity, Float:vector[3]) {

  Entity_GetAbsOrigin(entity, vector);

  new parent = Entity_GetParent(entity);

  if (parent > 0) {
    decl Float:parent_vector[3];
    Entity_GetTrueAbsOrigin(parent, parent_vector);
    AddVectors(vector, parent_vector, vector);
  }

}
