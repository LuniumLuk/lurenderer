#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "global.hpp"
#include "buffer.hpp"
#include "maths.hpp"
#include "camera.hpp"
#include "entity.hpp"
#include "scene.hpp"
#include "light.hpp"
#include "colormap.hpp"

namespace LuGL
{

#define SAMPLER_2D(tex,coord) (Texture::sampler(tex,coord))
#define TEXTURE_ALBEDO (entity->getMaterial()->albedo)
#define TEXTURE_DIFFUSE (entity->getMaterial()->diffuse)
#define TEXTURE_SPECULAR (entity->getMaterial()->specular)
#define TEXTURE_NORMAL (entity->getMaterial()->normal)


struct vdata
{
    mat4 model_mat;
    mat3 model_inv_transpose;
    mat4 mvp_mat;
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
    vec3 tangent;
    vec3 bitangent;
};

struct v2f
{
    vec4 position;
    vec3 frag_pos;
    vec3 normal;
    vec3 t_normal;
    vec2 texcoord;
    vec3 tangent;
    vec3 bitangent;

    v2f() {}

    v2f(vec4 a_position, vec3 a_frag_pos, vec3 a_normal, vec3 a_t_normal, vec2 a_texcoord, vec3 a_tangent, vec3 a_bitangent)
    {
        position = a_position;
        frag_pos = a_frag_pos;
        normal = a_normal;
        t_normal = a_t_normal;
        texcoord = a_texcoord;
        tangent = a_tangent;
        bitangent = a_bitangent;
    }
};

class Scene;

class Shader
{
public:
    virtual v2f vert(const vdata in, const Entity * entity, const Scene & scene) const = 0;
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const = 0;
};

#define MODEL_MATRIX        (in.model_mat)
#define MODEL_INV_TRANSPOSE (in.model_inv_transpose)
#define VIEW_MATRIX         (scene.getCamera().getViewMatrix())
#define PERSPECTIVE_MATRIX  (scene.getCamera().getProjectMatrix())
#define MVP_MATRIX          (in.mvp_mat)
#define TBN_MATRIX          (mat3(in.tangent.x, in.bitangent.x, in.normal.x, \
                                  in.tangent.y, in.bitangent.y, in.normal.y, \
                                  in.tangent.z, in.bitangent.z, in.normal.z))

class UnlitShader : public Shader
{
public:
    virtual v2f vert(const vdata in, const Entity * entity, const Scene & scene) const;
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

class TriangleNormalShader : public UnlitShader
{
public:
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

class VertexNormalShader : public UnlitShader
{
public:
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

class DepthShader : public UnlitShader
{
public:
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

class LitShader : public Shader
{
public:
    virtual v2f vert(const vdata in, const Entity * entity, const Scene & scene) const;
};

class BlinnPhongShader : LitShader
{
public:
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

class NormalMappingShader : public LitShader
{
public:
    virtual vec4 frag(const v2f in, const Entity * entity, const Scene & scene) const;
};

}

#endif