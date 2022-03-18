/*****************************************************************************\
*
*  Module Name    RPRStringIDMapper.cpp
*  Project        AMD Radeon ProRender
*
*  Description    Radeon ProRender Interface header
*
*  Copyright(C) 2017-2021 Advanced Micro Devices, Inc. All rights reserved.
*
\*****************************************************************************/

#include "RPRStringIDMapper.h"
#include "RadeonProRender_Baikal.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <functional>


RPRStringIDMapper::RPRStringIDMapper()
{

	#define MACRO_LINK_STR_ID(s,i)  m_RPRMaterialInput_string_to_id[s]=i;  m_RPRMaterialInput_id_to_string[i]=s  ;


	//
	// MAKE SURE ALL STRINGS ARE IN LOWER CASE ONLY
	//

	MACRO_LINK_STR_ID("color",RPR_MATERIAL_INPUT_COLOR);
	MACRO_LINK_STR_ID("color0",RPR_MATERIAL_INPUT_COLOR0);
	MACRO_LINK_STR_ID("color1",RPR_MATERIAL_INPUT_COLOR1);
	MACRO_LINK_STR_ID("color2",RPR_MATERIAL_INPUT_COLOR2);
	MACRO_LINK_STR_ID("color3",RPR_MATERIAL_INPUT_COLOR3);
	MACRO_LINK_STR_ID("normal",RPR_MATERIAL_INPUT_NORMAL);
	MACRO_LINK_STR_ID("uv",RPR_MATERIAL_INPUT_UV);
	MACRO_LINK_STR_ID("data",RPR_MATERIAL_INPUT_DATA);
	MACRO_LINK_STR_ID("roughness",RPR_MATERIAL_INPUT_ROUGHNESS);
	MACRO_LINK_STR_ID("ior",RPR_MATERIAL_INPUT_IOR);
	MACRO_LINK_STR_ID("roughness_x",RPR_MATERIAL_INPUT_ROUGHNESS_X);
	MACRO_LINK_STR_ID("roughness_y",RPR_MATERIAL_INPUT_ROUGHNESS_Y);
	MACRO_LINK_STR_ID("rotation",RPR_MATERIAL_INPUT_ROTATION);
	MACRO_LINK_STR_ID("weight",RPR_MATERIAL_INPUT_WEIGHT);
	MACRO_LINK_STR_ID("op",RPR_MATERIAL_INPUT_OP);
	MACRO_LINK_STR_ID("invec",RPR_MATERIAL_INPUT_INVEC);
	MACRO_LINK_STR_ID("uv_scale",RPR_MATERIAL_INPUT_UV_SCALE);
	MACRO_LINK_STR_ID("value",RPR_MATERIAL_INPUT_VALUE);
	MACRO_LINK_STR_ID("reflectance",RPR_MATERIAL_INPUT_REFLECTANCE);
	MACRO_LINK_STR_ID("bumpscale",RPR_MATERIAL_INPUT_SCALE);
	MACRO_LINK_STR_ID("sigmas",RPR_MATERIAL_INPUT_SCATTERING);
	MACRO_LINK_STR_ID("sigmaa",RPR_MATERIAL_INPUT_ABSORBTION);
	MACRO_LINK_STR_ID("emission",RPR_MATERIAL_INPUT_EMISSION);
	MACRO_LINK_STR_ID("g",RPR_MATERIAL_INPUT_G);
	MACRO_LINK_STR_ID("multiscatter",RPR_MATERIAL_INPUT_MULTISCATTER);
	MACRO_LINK_STR_ID("anisotropic",RPR_MATERIAL_INPUT_ANISOTROPIC);
	MACRO_LINK_STR_ID("frontface",RPR_MATERIAL_INPUT_FRONTFACE);
	MACRO_LINK_STR_ID("backface",RPR_MATERIAL_INPUT_BACKFACE);
	MACRO_LINK_STR_ID("origin",RPR_MATERIAL_INPUT_ORIGIN);
	MACRO_LINK_STR_ID("zaxis",RPR_MATERIAL_INPUT_ZAXIS);
	MACRO_LINK_STR_ID("xaxis",RPR_MATERIAL_INPUT_XAXIS);
	MACRO_LINK_STR_ID("threshold",RPR_MATERIAL_INPUT_THRESHOLD);
	MACRO_LINK_STR_ID("offset",RPR_MATERIAL_INPUT_OFFSET);
	MACRO_LINK_STR_ID("uv_type",RPR_MATERIAL_INPUT_UV_TYPE);
	MACRO_LINK_STR_ID("radius",RPR_MATERIAL_INPUT_RADIUS);
	MACRO_LINK_STR_ID("side",RPR_MATERIAL_INPUT_SIDE);
	MACRO_LINK_STR_ID("caustics",RPR_MATERIAL_INPUT_CAUSTICS);
	MACRO_LINK_STR_ID("transmission_color",RPR_MATERIAL_INPUT_TRANSMISSION_COLOR);
	MACRO_LINK_STR_ID("thickness",RPR_MATERIAL_INPUT_THICKNESS);
	MACRO_LINK_STR_ID("input0",RPR_MATERIAL_INPUT_0);
	MACRO_LINK_STR_ID("input1",RPR_MATERIAL_INPUT_1);
	MACRO_LINK_STR_ID("input2",RPR_MATERIAL_INPUT_2);
	MACRO_LINK_STR_ID("input3",RPR_MATERIAL_INPUT_3);
	MACRO_LINK_STR_ID("input4",RPR_MATERIAL_INPUT_4);
	MACRO_LINK_STR_ID("input5",RPR_MATERIAL_INPUT_5);
	MACRO_LINK_STR_ID("input6",RPR_MATERIAL_INPUT_6);
	MACRO_LINK_STR_ID("input7",RPR_MATERIAL_INPUT_7);
	MACRO_LINK_STR_ID("input8",RPR_MATERIAL_INPUT_8);
	MACRO_LINK_STR_ID("input9",RPR_MATERIAL_INPUT_9);
	MACRO_LINK_STR_ID("input10",RPR_MATERIAL_INPUT_10);
	MACRO_LINK_STR_ID("input11",RPR_MATERIAL_INPUT_11);
	MACRO_LINK_STR_ID("input12",RPR_MATERIAL_INPUT_12);
	MACRO_LINK_STR_ID("input13",RPR_MATERIAL_INPUT_13);
	MACRO_LINK_STR_ID("input14",RPR_MATERIAL_INPUT_14);
	MACRO_LINK_STR_ID("input15",RPR_MATERIAL_INPUT_15);
	MACRO_LINK_STR_ID("diffuse_ramp",RPR_MATERIAL_INPUT_DIFFUSE_RAMP);
	MACRO_LINK_STR_ID("shadow",RPR_MATERIAL_INPUT_SHADOW);
	MACRO_LINK_STR_ID("mid",RPR_MATERIAL_INPUT_MID);
	MACRO_LINK_STR_ID("highlight",RPR_MATERIAL_INPUT_HIGHLIGHT);
	MACRO_LINK_STR_ID("position1",RPR_MATERIAL_INPUT_POSITION1);
	MACRO_LINK_STR_ID("position2",RPR_MATERIAL_INPUT_POSITION2);
	MACRO_LINK_STR_ID("range1",RPR_MATERIAL_INPUT_RANGE1);
	MACRO_LINK_STR_ID("range2",RPR_MATERIAL_INPUT_RANGE2);
	MACRO_LINK_STR_ID("interpolation",RPR_MATERIAL_INPUT_INTERPOLATION);
	MACRO_LINK_STR_ID("schlickapprox",RPR_MATERIAL_INPUT_SCHLICK_APPROXIMATION);
	MACRO_LINK_STR_ID("applysurface",RPR_MATERIAL_INPUT_APPLYSURFACE);
	MACRO_LINK_STR_ID("tangent",RPR_MATERIAL_INPUT_TANGENT);
	MACRO_LINK_STR_ID("distribution",RPR_MATERIAL_INPUT_DISTRIBUTION);
	MACRO_LINK_STR_ID("base",RPR_MATERIAL_INPUT_BASE);
	MACRO_LINK_STR_ID("tint",RPR_MATERIAL_INPUT_TINT);
	MACRO_LINK_STR_ID("exponent",RPR_MATERIAL_INPUT_EXPONENT);
	MACRO_LINK_STR_ID("amplitude",RPR_MATERIAL_INPUT_AMPLITUDE);
	MACRO_LINK_STR_ID("pivot",RPR_MATERIAL_INPUT_PIVOT);
	MACRO_LINK_STR_ID("position",RPR_MATERIAL_INPUT_POSITION);
	MACRO_LINK_STR_ID("amount",RPR_MATERIAL_INPUT_AMOUNT);
	MACRO_LINK_STR_ID("axis",RPR_MATERIAL_INPUT_AXIS);
	MACRO_LINK_STR_ID("lumacoeff",RPR_MATERIAL_INPUT_LUMACOEFF);
	MACRO_LINK_STR_ID("reflectivity",RPR_MATERIAL_INPUT_REFLECTIVITY);
	MACRO_LINK_STR_ID("edgecolor",RPR_MATERIAL_INPUT_EDGE_COLOR);
	MACRO_LINK_STR_ID("viewdirection",RPR_MATERIAL_INPUT_VIEW_DIRECTION);
	MACRO_LINK_STR_ID("interior",RPR_MATERIAL_INPUT_INTERIOR);
	MACRO_LINK_STR_ID("octaves",RPR_MATERIAL_INPUT_OCTAVES);
	MACRO_LINK_STR_ID("lacunarity",RPR_MATERIAL_INPUT_LACUNARITY);
	MACRO_LINK_STR_ID("diminish",RPR_MATERIAL_INPUT_DIMINISH);
	MACRO_LINK_STR_ID("wrap_u",RPR_MATERIAL_INPUT_WRAP_U);
	MACRO_LINK_STR_ID("wrap_v",RPR_MATERIAL_INPUT_WRAP_V);
	MACRO_LINK_STR_ID("wrap_w",RPR_MATERIAL_INPUT_WRAP_W);
	MACRO_LINK_STR_ID("randomness",RPR_MATERIAL_INPUT_RANDOMNESS);
	MACRO_LINK_STR_ID("dimension",RPR_MATERIAL_INPUT_DIMENSION);
	MACRO_LINK_STR_ID("outtype",RPR_MATERIAL_INPUT_OUTTYPE);
	MACRO_LINK_STR_ID("density",RPR_MATERIAL_INPUT_DENSITY);
	MACRO_LINK_STR_ID("densitygrid",RPR_MATERIAL_INPUT_DENSITYGRID);
	MACRO_LINK_STR_ID("displacement",RPR_MATERIAL_INPUT_DISPLACEMENT);
	MACRO_LINK_STR_ID("temperature",RPR_MATERIAL_INPUT_TEMPERATURE);
	MACRO_LINK_STR_ID("kelvin",RPR_MATERIAL_INPUT_KELVIN);
	MACRO_LINK_STR_ID("extinction",RPR_MATERIAL_INPUT_EXTINCTION);
	MACRO_LINK_STR_ID("thinfilm",RPR_MATERIAL_INPUT_THIN_FILM);
	MACRO_LINK_STR_ID("top",RPR_MATERIAL_INPUT_TOP);
	MACRO_LINK_STR_ID("highlight2",RPR_MATERIAL_INPUT_HIGHLIGHT2);
	MACRO_LINK_STR_ID("shadow2",RPR_MATERIAL_INPUT_SHADOW2);
	MACRO_LINK_STR_ID("pos_shadow",RPR_MATERIAL_INPUT_POSITION_SHADOW);
	MACRO_LINK_STR_ID("pos_highlight",RPR_MATERIAL_INPUT_POSITION_HIGHLIGHT);
	MACRO_LINK_STR_ID("range_shadow",RPR_MATERIAL_INPUT_RANGE_SHADOW);
	MACRO_LINK_STR_ID("range_highlight",RPR_MATERIAL_INPUT_RANGE_HIGHLIGHT);
	MACRO_LINK_STR_ID("toon_5_colors",RPR_MATERIAL_INPUT_TOON_5_COLORS);
	MACRO_LINK_STR_ID("x",RPR_MATERIAL_INPUT_X);
	MACRO_LINK_STR_ID("y",RPR_MATERIAL_INPUT_Y);
	MACRO_LINK_STR_ID("z",RPR_MATERIAL_INPUT_Z);
	MACRO_LINK_STR_ID("w",RPR_MATERIAL_INPUT_W);
	MACRO_LINK_STR_ID("light",RPR_MATERIAL_INPUT_LIGHT);
	MACRO_LINK_STR_ID("mid_is_albedo",RPR_MATERIAL_INPUT_MID_IS_ALBEDO);

	//
	//list of RPR_MATERIAL_INPUT_UBER_ from RPRHybrid
	//
	MACRO_LINK_STR_ID("uberv2.diffuse_color",RPR_MATERIAL_INPUT_UBER_DIFFUSE_COLOR);
	MACRO_LINK_STR_ID("uberv2.diffuse_roughness",RPR_MATERIAL_INPUT_UBER_DIFFUSE_ROUGHNESS);
	MACRO_LINK_STR_ID("uberv2.diffuse_normal",RPR_MATERIAL_INPUT_UBER_DIFFUSE_NORMAL);
	MACRO_LINK_STR_ID("uberv2.diffuse_weight",RPR_MATERIAL_INPUT_UBER_DIFFUSE_WEIGHT);
	MACRO_LINK_STR_ID("uberv2.reflection_color",RPR_MATERIAL_INPUT_UBER_REFLECTION_COLOR);
	MACRO_LINK_STR_ID("uberv2.reflection_roughness",RPR_MATERIAL_INPUT_UBER_REFLECTION_ROUGHNESS);
	MACRO_LINK_STR_ID("uberv2.reflection_anisotropy",RPR_MATERIAL_INPUT_UBER_REFLECTION_ANISOTROPY);
	MACRO_LINK_STR_ID("uberv2.reflection_anysotropy_rotation",RPR_MATERIAL_INPUT_UBER_REFLECTION_ANISOTROPY_ROTATION);
	MACRO_LINK_STR_ID("uberv2.reflection_mode",RPR_MATERIAL_INPUT_UBER_REFLECTION_MODE);
	MACRO_LINK_STR_ID("uberv2.reflection_ior",RPR_MATERIAL_INPUT_UBER_REFLECTION_IOR);
	MACRO_LINK_STR_ID("uberv2.reflection_metalness",RPR_MATERIAL_INPUT_UBER_REFLECTION_METALNESS);
	MACRO_LINK_STR_ID("uberv2.reflection_weight",RPR_MATERIAL_INPUT_UBER_REFLECTION_WEIGHT);
	MACRO_LINK_STR_ID("uberv2.refraction_color",RPR_MATERIAL_INPUT_UBER_REFRACTION_COLOR);
	MACRO_LINK_STR_ID("uberv2.refraction_roughness",RPR_MATERIAL_INPUT_UBER_REFRACTION_ROUGHNESS);
	MACRO_LINK_STR_ID("uberv2.refraction_ior",RPR_MATERIAL_INPUT_UBER_REFRACTION_IOR);
	MACRO_LINK_STR_ID("uberv2.refraction_thin_surface",RPR_MATERIAL_INPUT_UBER_REFRACTION_THIN_SURFACE);
	MACRO_LINK_STR_ID("uberv2.refraction_weight",RPR_MATERIAL_INPUT_UBER_REFRACTION_WEIGHT);
	MACRO_LINK_STR_ID("uberv2.coating_color",RPR_MATERIAL_INPUT_UBER_COATING_COLOR);
	MACRO_LINK_STR_ID("uberv2.coating_roughness",RPR_MATERIAL_INPUT_UBER_COATING_ROUGHNESS);
	MACRO_LINK_STR_ID("uberv2.coating_mode",RPR_MATERIAL_INPUT_UBER_COATING_MODE);
	MACRO_LINK_STR_ID("uberv2.coating_ior",RPR_MATERIAL_INPUT_UBER_COATING_IOR);
	MACRO_LINK_STR_ID("uberv2.coating_metalness",RPR_MATERIAL_INPUT_UBER_COATING_METALNESS);
	MACRO_LINK_STR_ID("uberv2.coating_normal",RPR_MATERIAL_INPUT_UBER_COATING_NORMAL);
	MACRO_LINK_STR_ID("uberv2.coating_weight",RPR_MATERIAL_INPUT_UBER_COATING_WEIGHT);
	MACRO_LINK_STR_ID("uberv2.emission_color",RPR_MATERIAL_INPUT_UBER_EMISSION_COLOR);
	MACRO_LINK_STR_ID("uberv2.emission_weight",RPR_MATERIAL_INPUT_UBER_EMISSION_WEIGHT);
	MACRO_LINK_STR_ID("uberv2.transparency",RPR_MATERIAL_INPUT_UBER_TRANSPARENCY);
	
	//
	// list of RPR_MATERIAL_INPUT_UBER_ from RPR-Tahoe
	//
	MACRO_LINK_STR_ID("diffuse.color",RPR_MATERIAL_INPUT_UBER_DIFFUSE_COLOR);
	MACRO_LINK_STR_ID("diffuse.weight",RPR_MATERIAL_INPUT_UBER_DIFFUSE_WEIGHT);
	MACRO_LINK_STR_ID("diffuse.roughness",RPR_MATERIAL_INPUT_UBER_DIFFUSE_ROUGHNESS);
	MACRO_LINK_STR_ID("diffuse.normal",RPR_MATERIAL_INPUT_UBER_DIFFUSE_NORMAL);
	MACRO_LINK_STR_ID("reflection.color",RPR_MATERIAL_INPUT_UBER_REFLECTION_COLOR);
	MACRO_LINK_STR_ID("reflection.weight",RPR_MATERIAL_INPUT_UBER_REFLECTION_WEIGHT);
	MACRO_LINK_STR_ID("reflection.roughness",RPR_MATERIAL_INPUT_UBER_REFLECTION_ROUGHNESS);
	MACRO_LINK_STR_ID("reflection.anisotropy",RPR_MATERIAL_INPUT_UBER_REFLECTION_ANISOTROPY);
	MACRO_LINK_STR_ID("reflection.anistropyrotation",RPR_MATERIAL_INPUT_UBER_REFLECTION_ANISOTROPY_ROTATION);
	MACRO_LINK_STR_ID("reflection.mode",RPR_MATERIAL_INPUT_UBER_REFLECTION_MODE);
	MACRO_LINK_STR_ID("reflection.ior",RPR_MATERIAL_INPUT_UBER_REFLECTION_IOR);
	MACRO_LINK_STR_ID("reflection.metalness",RPR_MATERIAL_INPUT_UBER_REFLECTION_METALNESS);
	MACRO_LINK_STR_ID("reflection.normal",RPR_MATERIAL_INPUT_UBER_REFLECTION_NORMAL);
	MACRO_LINK_STR_ID("reflection.dielectricreflectance",RPR_MATERIAL_INPUT_UBER_REFLECTION_DIELECTRIC_REFLECTANCE);
	MACRO_LINK_STR_ID("refraction.color",RPR_MATERIAL_INPUT_UBER_REFRACTION_COLOR);
	MACRO_LINK_STR_ID("refraction.weight",RPR_MATERIAL_INPUT_UBER_REFRACTION_WEIGHT);
	MACRO_LINK_STR_ID("refraction.roughness",RPR_MATERIAL_INPUT_UBER_REFRACTION_ROUGHNESS);
	MACRO_LINK_STR_ID("refraction.ior",RPR_MATERIAL_INPUT_UBER_REFRACTION_IOR);
	MACRO_LINK_STR_ID("refraction.normal",RPR_MATERIAL_INPUT_UBER_REFRACTION_NORMAL);
	MACRO_LINK_STR_ID("refraction.thinsurface",RPR_MATERIAL_INPUT_UBER_REFRACTION_THIN_SURFACE);
	MACRO_LINK_STR_ID("refraction.absorptioncolor",RPR_MATERIAL_INPUT_UBER_REFRACTION_ABSORPTION_COLOR);
	MACRO_LINK_STR_ID("refraction.absorptiondistance",RPR_MATERIAL_INPUT_UBER_REFRACTION_ABSORPTION_DISTANCE);
	MACRO_LINK_STR_ID("refraction.caustics",RPR_MATERIAL_INPUT_UBER_REFRACTION_CAUSTICS);
	MACRO_LINK_STR_ID("coating.color",RPR_MATERIAL_INPUT_UBER_COATING_COLOR);
	MACRO_LINK_STR_ID("coating.weight",RPR_MATERIAL_INPUT_UBER_COATING_WEIGHT);
	MACRO_LINK_STR_ID("coating.roughness",RPR_MATERIAL_INPUT_UBER_COATING_ROUGHNESS);
	MACRO_LINK_STR_ID("coating.mode",RPR_MATERIAL_INPUT_UBER_COATING_MODE);
	MACRO_LINK_STR_ID("coating.ior",RPR_MATERIAL_INPUT_UBER_COATING_IOR);
	MACRO_LINK_STR_ID("coating.metalness",RPR_MATERIAL_INPUT_UBER_COATING_METALNESS);
	MACRO_LINK_STR_ID("coating.normal",RPR_MATERIAL_INPUT_UBER_COATING_NORMAL);
	MACRO_LINK_STR_ID("coating.transmissioncolor",RPR_MATERIAL_INPUT_UBER_COATING_TRANSMISSION_COLOR);
	MACRO_LINK_STR_ID("coating.thickness",RPR_MATERIAL_INPUT_UBER_COATING_THICKNESS);
	MACRO_LINK_STR_ID("sheen",RPR_MATERIAL_INPUT_UBER_SHEEN);
	MACRO_LINK_STR_ID("sheen.tint",RPR_MATERIAL_INPUT_UBER_SHEEN_TINT);
	MACRO_LINK_STR_ID("sheen.weight",RPR_MATERIAL_INPUT_UBER_SHEEN_WEIGHT);
	MACRO_LINK_STR_ID("emission.color",RPR_MATERIAL_INPUT_UBER_EMISSION_COLOR);
	MACRO_LINK_STR_ID("emission.weight",RPR_MATERIAL_INPUT_UBER_EMISSION_WEIGHT);
	MACRO_LINK_STR_ID("emission.mode",RPR_MATERIAL_INPUT_UBER_EMISSION_MODE);
	MACRO_LINK_STR_ID("transparency",RPR_MATERIAL_INPUT_UBER_TRANSPARENCY);
	MACRO_LINK_STR_ID("sss.scattercolor",RPR_MATERIAL_INPUT_UBER_SSS_SCATTER_COLOR);
	MACRO_LINK_STR_ID("sss.scatterdistance",RPR_MATERIAL_INPUT_UBER_SSS_SCATTER_DISTANCE);
	MACRO_LINK_STR_ID("sss.scatterdirection",RPR_MATERIAL_INPUT_UBER_SSS_SCATTER_DIRECTION);
	MACRO_LINK_STR_ID("sss.weight",RPR_MATERIAL_INPUT_UBER_SSS_WEIGHT);
	MACRO_LINK_STR_ID("sss.multiscatter",RPR_MATERIAL_INPUT_UBER_SSS_MULTISCATTER);
	MACRO_LINK_STR_ID("backscatter.weight",RPR_MATERIAL_INPUT_UBER_BACKSCATTER_WEIGHT);
	MACRO_LINK_STR_ID("backscatter.color",RPR_MATERIAL_INPUT_UBER_BACKSCATTER_COLOR);
	MACRO_LINK_STR_ID("schlickapprox",RPR_MATERIAL_INPUT_UBER_FRESNEL_SCHLICK_APPROXIMATION);




	#undef MACRO_LINK_STR_ID
	#define MACRO_LINK_STR_ID(s,i)  m_RPRContextInput_string_to_id[s]=i;  m_RPRContextInput_id_to_string[i]=s  ;

	// deprecated API first
	MACRO_LINK_STR_ID("usertexture0",RPR_CONTEXT_USER_TEXTURE_0);
	MACRO_LINK_STR_ID("usertexture1",RPR_CONTEXT_USER_TEXTURE_1);
	MACRO_LINK_STR_ID("usertexture2",RPR_CONTEXT_USER_TEXTURE_2);
	MACRO_LINK_STR_ID("usertexture3",RPR_CONTEXT_USER_TEXTURE_3);

	MACRO_LINK_STR_ID("iterations",RPR_CONTEXT_ITERATIONS);
	MACRO_LINK_STR_ID("imagefilter.type",RPR_CONTEXT_IMAGE_FILTER_TYPE);
	MACRO_LINK_STR_ID("imagefilter.box.radius",RPR_CONTEXT_IMAGE_FILTER_BOX_RADIUS);
	MACRO_LINK_STR_ID("imagefilter.gaussian.radius",RPR_CONTEXT_IMAGE_FILTER_GAUSSIAN_RADIUS);
	MACRO_LINK_STR_ID("imagefilter.triangle.radius",RPR_CONTEXT_IMAGE_FILTER_TRIANGLE_RADIUS);
	MACRO_LINK_STR_ID("imagefilter.mitchell.radius",RPR_CONTEXT_IMAGE_FILTER_MITCHELL_RADIUS);
	MACRO_LINK_STR_ID("imagefilter.lanczos.radius",RPR_CONTEXT_IMAGE_FILTER_LANCZOS_RADIUS);
	MACRO_LINK_STR_ID("imagefilter.blackmanharris.radius",RPR_CONTEXT_IMAGE_FILTER_BLACKMANHARRIS_RADIUS);
	MACRO_LINK_STR_ID("tonemapping.type",RPR_CONTEXT_TONE_MAPPING_TYPE);
	MACRO_LINK_STR_ID("tonemapping.linear.scale",RPR_CONTEXT_TONE_MAPPING_LINEAR_SCALE);
	MACRO_LINK_STR_ID("tonemapping.photolinear.sensitivity",RPR_CONTEXT_TONE_MAPPING_PHOTO_LINEAR_SENSITIVITY);
	MACRO_LINK_STR_ID("tonemapping.photolinear.exposure",RPR_CONTEXT_TONE_MAPPING_PHOTO_LINEAR_EXPOSURE);
	MACRO_LINK_STR_ID("tonemapping.photolinear.fstop",RPR_CONTEXT_TONE_MAPPING_PHOTO_LINEAR_FSTOP);
	MACRO_LINK_STR_ID("tonemapping.exponential.intensity",RPR_CONTEXT_TONE_MAPPING_EXPONENTIAL_INTENSITY);
	MACRO_LINK_STR_ID("tonemapping.reinhard02.prescale",RPR_CONTEXT_TONE_MAPPING_REINHARD02_PRE_SCALE);
	MACRO_LINK_STR_ID("tonemapping.reinhard02.postscale",RPR_CONTEXT_TONE_MAPPING_REINHARD02_POST_SCALE);
	MACRO_LINK_STR_ID("tonemapping.reinhard02.burn",RPR_CONTEXT_TONE_MAPPING_REINHARD02_BURN);
	MACRO_LINK_STR_ID("maxrecursion",RPR_CONTEXT_MAX_RECURSION);
	MACRO_LINK_STR_ID("raycastepsilon",RPR_CONTEXT_RAY_CAST_EPISLON);
	MACRO_LINK_STR_ID("aoraylength",RPR_CONTEXT_AO_RAY_LENGTH);
	MACRO_LINK_STR_ID("radianceclamp",RPR_CONTEXT_RADIANCE_CLAMP);
	MACRO_LINK_STR_ID("xflip",RPR_CONTEXT_X_FLIP);
	MACRO_LINK_STR_ID("yflip",RPR_CONTEXT_Y_FLIP);
	MACRO_LINK_STR_ID("transparentbackground",RPR_CONTEXT_TRANSPARENT_BACKGROUND);
	MACRO_LINK_STR_ID("preview",RPR_CONTEXT_PREVIEW);
	MACRO_LINK_STR_ID("framecount",RPR_CONTEXT_FRAMECOUNT);
	MACRO_LINK_STR_ID("ooctexcache",RPR_CONTEXT_OOC_TEXTURE_CACHE);
	MACRO_LINK_STR_ID("texturegamma",RPR_CONTEXT_TEXTURE_GAMMA);
	MACRO_LINK_STR_ID("displaygamma",RPR_CONTEXT_DISPLAY_GAMMA);
	MACRO_LINK_STR_ID("mipmaplodoffset",RPR_CONTEXT_MIPMAP_LOD_OFFSET);
	MACRO_LINK_STR_ID("cuttingplanes",RPR_CONTEXT_CUTTING_PLANES);
	MACRO_LINK_STR_ID("stacksize",RPR_CONTEXT_MATERIAL_STACK_SIZE);
	MACRO_LINK_STR_ID("pdfthreshold",RPR_CONTEXT_PDF_THRESHOLD);
	MACRO_LINK_STR_ID("rendermode",RPR_CONTEXT_RENDER_MODE);
	MACRO_LINK_STR_ID("roughnesscap",RPR_CONTEXT_ROUGHNESS_CAP);
	MACRO_LINK_STR_ID("gpu0name",RPR_CONTEXT_GPU0_NAME);
	MACRO_LINK_STR_ID("gpu1name",RPR_CONTEXT_GPU1_NAME);
	MACRO_LINK_STR_ID("gpu2name",RPR_CONTEXT_GPU2_NAME);
	MACRO_LINK_STR_ID("gpu3name",RPR_CONTEXT_GPU3_NAME);
	MACRO_LINK_STR_ID("gpu4name",RPR_CONTEXT_GPU4_NAME);
	MACRO_LINK_STR_ID("gpu5name",RPR_CONTEXT_GPU5_NAME);
	MACRO_LINK_STR_ID("gpu6name",RPR_CONTEXT_GPU6_NAME);
	MACRO_LINK_STR_ID("gpu7name",RPR_CONTEXT_GPU7_NAME);
	MACRO_LINK_STR_ID("gpu8name",RPR_CONTEXT_GPU8_NAME);
	MACRO_LINK_STR_ID("gpu9name",RPR_CONTEXT_GPU9_NAME);
	MACRO_LINK_STR_ID("gpu10name",RPR_CONTEXT_GPU10_NAME);
	MACRO_LINK_STR_ID("gpu11name",RPR_CONTEXT_GPU11_NAME);
	MACRO_LINK_STR_ID("gpu12name",RPR_CONTEXT_GPU12_NAME);
	MACRO_LINK_STR_ID("gpu13name",RPR_CONTEXT_GPU13_NAME);
	MACRO_LINK_STR_ID("gpu14name",RPR_CONTEXT_GPU14_NAME);
	MACRO_LINK_STR_ID("gpu15name",RPR_CONTEXT_GPU15_NAME);
	MACRO_LINK_STR_ID("cpuname",RPR_CONTEXT_CPU_NAME);
	MACRO_LINK_STR_ID("texturecompression",RPR_CONTEXT_TEXTURE_COMPRESSION);
	MACRO_LINK_STR_ID("cputhreadlimit",RPR_CONTEXT_CPU_THREAD_LIMIT);
	MACRO_LINK_STR_ID("rpr_api_version",RPR_CONTEXT_API_VERSION);
	MACRO_LINK_STR_ID("rpr_api_version_minor",RPR_CONTEXT_API_VERSION_MINOR);
	MACRO_LINK_STR_ID("lasterror",RPR_CONTEXT_LAST_ERROR_MESSAGE);
	MACRO_LINK_STR_ID("maxdepth.diffuse",RPR_CONTEXT_MAX_DEPTH_DIFFUSE);
	MACRO_LINK_STR_ID("maxdepth.shadow",RPR_CONTEXT_MAX_DEPTH_SHADOW);
	MACRO_LINK_STR_ID("maxdepth.glossy",RPR_CONTEXT_MAX_DEPTH_GLOSSY);
	MACRO_LINK_STR_ID("maxdepth.refraction",RPR_CONTEXT_MAX_DEPTH_REFRACTION);
	MACRO_LINK_STR_ID("maxdepth.refraction.glossy",RPR_CONTEXT_MAX_DEPTH_GLOSSY_REFRACTION);
	MACRO_LINK_STR_ID("ooccachepath",RPR_CONTEXT_OOC_CACHE_PATH);
	MACRO_LINK_STR_ID("renderlayermask",RPR_CONTEXT_RENDER_LAYER_MASK);
	MACRO_LINK_STR_ID("singlelevelbvh",RPR_CONTEXT_SINGLE_LEVEL_BVH_ENABLED);
	MACRO_LINK_STR_ID("metalperformanceshader",RPR_CONTEXT_METAL_PERFORMANCE_SHADER);
	MACRO_LINK_STR_ID("aoraycount",RPR_CONTEXT_AO_RAY_COUNT);
	MACRO_LINK_STR_ID("samplertype",RPR_CONTEXT_SAMPLER_TYPE);
	MACRO_LINK_STR_ID("as.tilesize",RPR_CONTEXT_ADAPTIVE_SAMPLING_TILE_SIZE);
	MACRO_LINK_STR_ID("as.minspp",RPR_CONTEXT_ADAPTIVE_SAMPLING_MIN_SPP);
	MACRO_LINK_STR_ID("as.threshold",RPR_CONTEXT_ADAPTIVE_SAMPLING_THRESHOLD);
	MACRO_LINK_STR_ID("tilesize",RPR_CONTEXT_TILE_SIZE);
	MACRO_LINK_STR_ID("listcreatedcameras",RPR_CONTEXT_LIST_CREATED_CAMERAS);
	MACRO_LINK_STR_ID("listcreatedmaterialnodes",RPR_CONTEXT_LIST_CREATED_MATERIALNODES);
	MACRO_LINK_STR_ID("listcreatedlights",RPR_CONTEXT_LIST_CREATED_LIGHTS);
	MACRO_LINK_STR_ID("listcreatedshapes",RPR_CONTEXT_LIST_CREATED_SHAPES);
	MACRO_LINK_STR_ID("listcreatedposteffects",RPR_CONTEXT_LIST_CREATED_POSTEFFECTS);
	MACRO_LINK_STR_ID("listcreatedheterovolumes",RPR_CONTEXT_LIST_CREATED_HETEROVOLUMES);
	MACRO_LINK_STR_ID("listcreatedgrids",RPR_CONTEXT_LIST_CREATED_GRIDS);
	MACRO_LINK_STR_ID("listcreatedbuffers",RPR_CONTEXT_LIST_CREATED_BUFFERS);
	MACRO_LINK_STR_ID("listcreatedimages",RPR_CONTEXT_LIST_CREATED_IMAGES);
	MACRO_LINK_STR_ID("listcreatedframebuffers",RPR_CONTEXT_LIST_CREATED_FRAMEBUFFERS);
	MACRO_LINK_STR_ID("listcreatedscenes",RPR_CONTEXT_LIST_CREATED_SCENES);
	MACRO_LINK_STR_ID("listcreatedcurves",RPR_CONTEXT_LIST_CREATED_CURVES);
	MACRO_LINK_STR_ID("listcreatedmaterialsystem",RPR_CONTEXT_LIST_CREATED_MATERIALSYSTEM);
	MACRO_LINK_STR_ID("listcreatedcomposite",RPR_CONTEXT_LIST_CREATED_COMPOSITE);
	MACRO_LINK_STR_ID("listcreatedlut",RPR_CONTEXT_LIST_CREATED_LUT);
	MACRO_LINK_STR_ID("aaenabled",RPR_CONTEXT_AA_ENABLED);
	MACRO_LINK_STR_ID("activepixelcount",RPR_CONTEXT_ACTIVE_PIXEL_COUNT);
	MACRO_LINK_STR_ID("tracing",RPR_CONTEXT_TRACING_ENABLED);
	MACRO_LINK_STR_ID("tracingfolder",RPR_CONTEXT_TRACING_PATH);
	MACRO_LINK_STR_ID("tilerect",RPR_CONTEXT_TILE_RECT);
	MACRO_LINK_STR_ID("pluginversion",RPR_CONTEXT_PLUGIN_VERSION);
	MACRO_LINK_STR_ID("russianroulettedepth",RPR_CONTEXT_RUSSIAN_ROULETTE_DEPTH);
	MACRO_LINK_STR_ID("shadowcatcherbaking",RPR_CONTEXT_SHADOW_CATCHER_BAKING);
	MACRO_LINK_STR_ID("renderupdatecallbackfunc",RPR_CONTEXT_RENDER_UPDATE_CALLBACK_FUNC);
	MACRO_LINK_STR_ID("renderupdatecallbackdata",RPR_CONTEXT_RENDER_UPDATE_CALLBACK_DATA);
	MACRO_LINK_STR_ID("compilecallbackfunc",RPR_CONTEXT_COMPILE_CALLBACK_FUNC);
	MACRO_LINK_STR_ID("compilecallbackdata",RPR_CONTEXT_COMPILE_CALLBACK_DATA);
	MACRO_LINK_STR_ID("texturecachepath",RPR_CONTEXT_TEXTURE_CACHE_PATH);
	MACRO_LINK_STR_ID("ocioconfigpath",RPR_CONTEXT_OCIO_CONFIG_PATH);
	MACRO_LINK_STR_ID("ociorenderingcolorspace",RPR_CONTEXT_OCIO_RENDERING_COLOR_SPACE);
	MACRO_LINK_STR_ID("contour.use_objectid",RPR_CONTEXT_CONTOUR_USE_OBJECTID);
	MACRO_LINK_STR_ID("contour.use_materialid",RPR_CONTEXT_CONTOUR_USE_MATERIALID);
	MACRO_LINK_STR_ID("contour.use_normal",RPR_CONTEXT_CONTOUR_USE_NORMAL);
	MACRO_LINK_STR_ID("contour.use_uv",RPR_CONTEXT_CONTOUR_USE_UV);
	MACRO_LINK_STR_ID("contour.normal_threshold",RPR_CONTEXT_CONTOUR_NORMAL_THRESHOLD);
	MACRO_LINK_STR_ID("contour.uv_threshold",RPR_CONTEXT_CONTOUR_UV_THRESHOLD);
	MACRO_LINK_STR_ID("contour.linewidth_objectid",RPR_CONTEXT_CONTOUR_LINEWIDTH_OBJECTID);
	MACRO_LINK_STR_ID("contour.linewidth_materialid",RPR_CONTEXT_CONTOUR_LINEWIDTH_MATERIALID);
	MACRO_LINK_STR_ID("contour.linewidth_normal",RPR_CONTEXT_CONTOUR_LINEWIDTH_NORMAL);
	MACRO_LINK_STR_ID("contour.linewidth_uv",RPR_CONTEXT_CONTOUR_LINEWIDTH_UV);
	MACRO_LINK_STR_ID("contour.antialiasing",RPR_CONTEXT_CONTOUR_ANTIALIASING);
	MACRO_LINK_STR_ID("contour.debug_enabled",RPR_CONTEXT_CONTOUR_DEBUG_ENABLED);
	MACRO_LINK_STR_ID("gpuintegrator",RPR_CONTEXT_GPUINTEGRATOR);
	MACRO_LINK_STR_ID("cpuintegrator",RPR_CONTEXT_CPUINTEGRATOR);
	MACRO_LINK_STR_ID("beautymotionblur",RPR_CONTEXT_BEAUTY_MOTION_BLUR);
	MACRO_LINK_STR_ID("causticsreduction",RPR_CONTEXT_CAUSTICS_REDUCTION);
	MACRO_LINK_STR_ID("deep.subpixelmergezthreshold", RPR_CONTEXT_DEEP_SUBPIXEL_MERGE_Z_THRESHOLD);
	MACRO_LINK_STR_ID("deep.gpuallocationlevel", RPR_CONTEXT_DEEP_GPU_ALLOCATION_LEVEL);
	MACRO_LINK_STR_ID("deep.colorenabled", RPR_CONTEXT_DEEP_COLOR_ENABLED);
	MACRO_LINK_STR_ID("gpumemorylimit",RPR_CONTEXT_GPU_MEMORY_LIMIT);
	MACRO_LINK_STR_ID("windingordercorrection",RPR_CONTEXT_WINDING_ORDER_CORRECTION);
	MACRO_LINK_STR_ID("fog.color",RPR_CONTEXT_FOG_COLOR);
	MACRO_LINK_STR_ID("fog.distance",RPR_CONTEXT_FOG_DISTANCE);
	MACRO_LINK_STR_ID("fog.height",RPR_CONTEXT_FOG_HEIGHT);
	MACRO_LINK_STR_ID("atmosphere.volume.color",RPR_CONTEXT_ATMOSPHERE_VOLUME_COLOR);
	MACRO_LINK_STR_ID("atmosphere.volume.density",RPR_CONTEXT_ATMOSPHERE_VOLUME_DENSITY);
	MACRO_LINK_STR_ID("atmosphere.volume.radianceclamp",RPR_CONTEXT_ATMOSPHERE_VOLUME_RADIANCE_CLAMP);
	MACRO_LINK_STR_ID("fog.height_offset",RPR_CONTEXT_FOG_HEIGHT_OFFSET);
	MACRO_LINK_STR_ID("cryptomatte.extended",RPR_CONTEXT_CRYPTOMATTE_EXTENDED);
	MACRO_LINK_STR_ID("cryptomatte.split_indirect",RPR_CONTEXT_CRYPTOMATTE_SPLIT_INDIRECT);
	MACRO_LINK_STR_ID("fog.direction",RPR_CONTEXT_FOG_DIRECTION);
	MACRO_LINK_STR_ID("randseed",RPR_CONTEXT_RANDOM_SEED);


	#undef MACRO_LINK_STR_ID
	#define MACRO_LINK_STR_ID(s,i)  m_RPRMaterialType_string_to_id[s]=i;  m_RPRMaterialType_id_to_string[i]=s  ;

	// deprecated API first
	MACRO_LINK_STR_ID("user_texture_0",RPR_MATERIAL_NODE_USER_TEXTURE_0); //0x27 
	MACRO_LINK_STR_ID("user_texture_1",RPR_MATERIAL_NODE_USER_TEXTURE_1); //0x28 
	MACRO_LINK_STR_ID("user_texture_2",RPR_MATERIAL_NODE_USER_TEXTURE_2); //0x29 
	MACRO_LINK_STR_ID("user_texture_3",RPR_MATERIAL_NODE_USER_TEXTURE_3); //0x2a 

	MACRO_LINK_STR_ID("diffuse",RPR_MATERIAL_NODE_DIFFUSE); //0x1 
	MACRO_LINK_STR_ID("microfacet",RPR_MATERIAL_NODE_MICROFACET); //0x2 
	MACRO_LINK_STR_ID("reflection",RPR_MATERIAL_NODE_REFLECTION); //0x3 
	MACRO_LINK_STR_ID("refraction",RPR_MATERIAL_NODE_REFRACTION); //0x4 
	MACRO_LINK_STR_ID("microfacet_refraction",RPR_MATERIAL_NODE_MICROFACET_REFRACTION); //0x5 
	MACRO_LINK_STR_ID("transparent",RPR_MATERIAL_NODE_TRANSPARENT); //0x6 
	MACRO_LINK_STR_ID("emissive",RPR_MATERIAL_NODE_EMISSIVE); //0x7 
	MACRO_LINK_STR_ID("ward",RPR_MATERIAL_NODE_WARD); //0x8 
	MACRO_LINK_STR_ID("add",RPR_MATERIAL_NODE_ADD); //0x9 
	MACRO_LINK_STR_ID("blend",RPR_MATERIAL_NODE_BLEND); //0xA 
	MACRO_LINK_STR_ID("arithmetic",RPR_MATERIAL_NODE_ARITHMETIC); //0xB 
	MACRO_LINK_STR_ID("fresnel",RPR_MATERIAL_NODE_FRESNEL); //0xC 
	MACRO_LINK_STR_ID("normal_map",RPR_MATERIAL_NODE_NORMAL_MAP); //0xD 
	MACRO_LINK_STR_ID("image_texture",RPR_MATERIAL_NODE_IMAGE_TEXTURE); //0xE 
	MACRO_LINK_STR_ID("noise2d_texture",RPR_MATERIAL_NODE_NOISE2D_TEXTURE); //0xF 
	MACRO_LINK_STR_ID("dot_texture",RPR_MATERIAL_NODE_DOT_TEXTURE); //0x10 
	MACRO_LINK_STR_ID("gradient_texture",RPR_MATERIAL_NODE_GRADIENT_TEXTURE); //0x11 
	MACRO_LINK_STR_ID("checker_texture",RPR_MATERIAL_NODE_CHECKER_TEXTURE); //0x12 
	MACRO_LINK_STR_ID("constant_texture",RPR_MATERIAL_NODE_CONSTANT_TEXTURE); //0x13 
	MACRO_LINK_STR_ID("input_lookup",RPR_MATERIAL_NODE_INPUT_LOOKUP); //0x14 
	MACRO_LINK_STR_ID("blend_value",RPR_MATERIAL_NODE_BLEND_VALUE); //0x16 
	MACRO_LINK_STR_ID("passthrough",RPR_MATERIAL_NODE_PASSTHROUGH); //0x17 
	MACRO_LINK_STR_ID("orennayar",RPR_MATERIAL_NODE_ORENNAYAR); //0x18 
	MACRO_LINK_STR_ID("fresnel_schlick",RPR_MATERIAL_NODE_FRESNEL_SCHLICK); //0x19 
	MACRO_LINK_STR_ID("diffuse_refraction",RPR_MATERIAL_NODE_DIFFUSE_REFRACTION); //0x1B 
	MACRO_LINK_STR_ID("bump_map",RPR_MATERIAL_NODE_BUMP_MAP); //0x1C 
	MACRO_LINK_STR_ID("volume",RPR_MATERIAL_NODE_VOLUME); //0x1D 
	MACRO_LINK_STR_ID("microfacet_anisotropic_reflection",RPR_MATERIAL_NODE_MICROFACET_ANISOTROPIC_REFLECTION); //0x1E 
	MACRO_LINK_STR_ID("microfacet_anisotropic_refraction",RPR_MATERIAL_NODE_MICROFACET_ANISOTROPIC_REFRACTION); //0x1F 
	MACRO_LINK_STR_ID("twosided",RPR_MATERIAL_NODE_TWOSIDED); //0x20 
	MACRO_LINK_STR_ID("uv_procedural",RPR_MATERIAL_NODE_UV_PROCEDURAL); //0x21 
	MACRO_LINK_STR_ID("microfacet_beckmann",RPR_MATERIAL_NODE_MICROFACET_BECKMANN); //0x22 
	MACRO_LINK_STR_ID("phong",RPR_MATERIAL_NODE_PHONG); //0x23 
	MACRO_LINK_STR_ID("buffer_sampler",RPR_MATERIAL_NODE_BUFFER_SAMPLER); //0x24 
	MACRO_LINK_STR_ID("uv_triplanar",RPR_MATERIAL_NODE_UV_TRIPLANAR); //0x25 
	MACRO_LINK_STR_ID("ao_map",RPR_MATERIAL_NODE_AO_MAP); //0x26 
	MACRO_LINK_STR_ID("uberv2",RPR_MATERIAL_NODE_UBERV2); //0x2b
	MACRO_LINK_STR_ID("transform",RPR_MATERIAL_NODE_TRANSFORM); //0x2c
	MACRO_LINK_STR_ID("rgb_to_hsv",RPR_MATERIAL_NODE_RGB_TO_HSV); //0x2d
	MACRO_LINK_STR_ID("hsv_to_rgb",RPR_MATERIAL_NODE_HSV_TO_RGB); //0x2e
	
	MACRO_LINK_STR_ID("matx_diffuse_brdf",RPR_MATERIAL_NODE_MATX_DIFFUSE_BRDF); //0x2f
	MACRO_LINK_STR_ID("matx_dielectric_brdf",RPR_MATERIAL_NODE_MATX_DIELECTRIC_BRDF); //0x30
	MACRO_LINK_STR_ID("matx_generalized_schlick_brdf",RPR_MATERIAL_NODE_MATX_GENERALIZED_SCHLICK_BRDF); //0x31
	MACRO_LINK_STR_ID("matx_generalized_schlick_btdf",RPR_MATERIAL_NODE_MATX_GENERALIZED_SCHLICK_BTDF);
	MACRO_LINK_STR_ID("matx_noise3d",RPR_MATERIAL_NODE_MATX_NOISE3D);
	MACRO_LINK_STR_ID("matx_tangent",RPR_MATERIAL_NODE_MATX_TANGENT);
	MACRO_LINK_STR_ID("matx_normal",RPR_MATERIAL_NODE_MATX_NORMAL);
	MACRO_LINK_STR_ID("matx_position",RPR_MATERIAL_NODE_MATX_POSITION);
	MACRO_LINK_STR_ID("matx_roughness_anisotropy",RPR_MATERIAL_NODE_MATX_ROUGHNESS_ANISOTROPY);
	MACRO_LINK_STR_ID("matx_rotate3d",RPR_MATERIAL_NODE_MATX_ROTATE3D);
	MACRO_LINK_STR_ID("matx_normalize",RPR_MATERIAL_NODE_MATX_NORMALIZE);
	MACRO_LINK_STR_ID("matx_ifgreater",RPR_MATERIAL_NODE_MATX_IFGREATER);
	MACRO_LINK_STR_ID("matx_sheen_brdf",RPR_MATERIAL_NODE_MATX_SHEEN_BRDF);
	MACRO_LINK_STR_ID("matx_diffuse_btdf",RPR_MATERIAL_NODE_MATX_DIFFUSE_BTDF);
	MACRO_LINK_STR_ID("matx_convert",RPR_MATERIAL_NODE_MATX_CONVERT);
	MACRO_LINK_STR_ID("matx_subsurface_brdf",RPR_MATERIAL_NODE_MATX_SUBSURFACE_BRDF);
	MACRO_LINK_STR_ID("matx_dielectric_btdf",RPR_MATERIAL_NODE_MATX_DIELECTRIC_BTDF);
	MACRO_LINK_STR_ID("matx_conductor_brdf",RPR_MATERIAL_NODE_MATX_CONDUCTOR_BRDF);
	MACRO_LINK_STR_ID("matx_fresnel",RPR_MATERIAL_NODE_MATX_FRESNEL);
	MACRO_LINK_STR_ID("matx_luminance",RPR_MATERIAL_NODE_MATX_LUMINANCE);
	MACRO_LINK_STR_ID("matx_fractal3d",RPR_MATERIAL_NODE_MATX_FRACTAL3D);
	MACRO_LINK_STR_ID("matx_mix",RPR_MATERIAL_NODE_MATX_MIX);
	MACRO_LINK_STR_ID("matx",RPR_MATERIAL_NODE_MATX);
	MACRO_LINK_STR_ID("matx_artistic_ior",RPR_MATERIAL_NODE_MATX_ARTISTIC_IOR);
	MACRO_LINK_STR_ID("matx_layer",RPR_MATERIAL_NODE_MATX_LAYER);
	MACRO_LINK_STR_ID("matx_thin_film",RPR_MATERIAL_NODE_MATX_THIN_FILM);
	MACRO_LINK_STR_ID("matx_bitangent",RPR_MATERIAL_NODE_MATX_BITANGENT);
	MACRO_LINK_STR_ID("matx_texcoord",RPR_MATERIAL_NODE_MATX_TEXCOORD);
	MACRO_LINK_STR_ID("matx_modulo",RPR_MATERIAL_NODE_MATX_MODULO);
	MACRO_LINK_STR_ID("matx_absval",RPR_MATERIAL_NODE_MATX_ABSVAL);
	MACRO_LINK_STR_ID("matx_sign",RPR_MATERIAL_NODE_MATX_SIGN);
	MACRO_LINK_STR_ID("matx_floor",RPR_MATERIAL_NODE_MATX_FLOOR);
	MACRO_LINK_STR_ID("matx_ceil",RPR_MATERIAL_NODE_MATX_CEIL);
	MACRO_LINK_STR_ID("matx_atan2",RPR_MATERIAL_NODE_MATX_ATAN2);
	MACRO_LINK_STR_ID("matx_sqrt",RPR_MATERIAL_NODE_MATX_SQRT);
	MACRO_LINK_STR_ID("matx_ln",RPR_MATERIAL_NODE_MATX_LN);
	MACRO_LINK_STR_ID("matx_exp",RPR_MATERIAL_NODE_MATX_EXP);
	MACRO_LINK_STR_ID("matx_clamp",RPR_MATERIAL_NODE_MATX_CLAMP);
	MACRO_LINK_STR_ID("matx_min",RPR_MATERIAL_NODE_MATX_MIN);
	MACRO_LINK_STR_ID("matx_max",RPR_MATERIAL_NODE_MATX_MAX);
	MACRO_LINK_STR_ID("matx_magnitude",RPR_MATERIAL_NODE_MATX_MAGNITUDE);
	MACRO_LINK_STR_ID("matx_crossproduct",RPR_MATERIAL_NODE_MATX_CROSSPRODUCT);
	MACRO_LINK_STR_ID("matx_remap",RPR_MATERIAL_NODE_MATX_REMAP);
	MACRO_LINK_STR_ID("matx_smoothstep",RPR_MATERIAL_NODE_MATX_SMOOTHSTEP);
	MACRO_LINK_STR_ID("matx_rgbtohsv",RPR_MATERIAL_NODE_MATX_RGBTOHSV);
	MACRO_LINK_STR_ID("matx_hsvtorgb",RPR_MATERIAL_NODE_MATX_HSVTORGB);
	MACRO_LINK_STR_ID("matx_ifgreatereq",RPR_MATERIAL_NODE_MATX_IFGREATEREQ);
	MACRO_LINK_STR_ID("matx_ifequal",RPR_MATERIAL_NODE_MATX_IFEQUAL);
	MACRO_LINK_STR_ID("matx_swizzle",RPR_MATERIAL_NODE_MATX_SWIZZLE);
	MACRO_LINK_STR_ID("matx_noise2d",RPR_MATERIAL_NODE_MATX_NOISE2D);
	MACRO_LINK_STR_ID("matx_plus",RPR_MATERIAL_NODE_MATX_PLUS);
	MACRO_LINK_STR_ID("matx_minus",RPR_MATERIAL_NODE_MATX_MINUS);
	MACRO_LINK_STR_ID("matx_difference",RPR_MATERIAL_NODE_MATX_DIFFERENCE);
	MACRO_LINK_STR_ID("matx_burn",RPR_MATERIAL_NODE_MATX_BURN);
	MACRO_LINK_STR_ID("matx_dodge",RPR_MATERIAL_NODE_MATX_DODGE);
	MACRO_LINK_STR_ID("matx_screen",RPR_MATERIAL_NODE_MATX_SCREEN);
	MACRO_LINK_STR_ID("matx_overlay",RPR_MATERIAL_NODE_MATX_OVERLAY);
	MACRO_LINK_STR_ID("matx_inside",RPR_MATERIAL_NODE_MATX_INSIDE);
	MACRO_LINK_STR_ID("matx_outside",RPR_MATERIAL_NODE_MATX_OUTSIDE);
	MACRO_LINK_STR_ID("matx_ramplr",RPR_MATERIAL_NODE_MATX_RAMPLR);
	MACRO_LINK_STR_ID("matx_ramptb",RPR_MATERIAL_NODE_MATX_RAMPTB);
	MACRO_LINK_STR_ID("matx_splitlr",RPR_MATERIAL_NODE_MATX_SPLITLR);
	MACRO_LINK_STR_ID("matx_splittb",RPR_MATERIAL_NODE_MATX_SPLITTB);
	MACRO_LINK_STR_ID("matx_cellnoise2d",RPR_MATERIAL_NODE_MATX_CELLNOISE2D);
	MACRO_LINK_STR_ID("matx_cellnoise3d",RPR_MATERIAL_NODE_MATX_CELLNOISE3D);
	MACRO_LINK_STR_ID("matx_rotate2d",RPR_MATERIAL_NODE_MATX_ROTATE2D);
	MACRO_LINK_STR_ID("matx_dot",RPR_MATERIAL_NODE_MATX_DOT);
	MACRO_LINK_STR_ID("matx_range",RPR_MATERIAL_NODE_MATX_RANGE);
	MACRO_LINK_STR_ID("matx_switch",RPR_MATERIAL_NODE_MATX_SWITCH);
	MACRO_LINK_STR_ID("matx_extract",RPR_MATERIAL_NODE_MATX_EXTRACT);
	MACRO_LINK_STR_ID("matx_combine2",RPR_MATERIAL_NODE_MATX_COMBINE2);
	MACRO_LINK_STR_ID("matx_combine3",RPR_MATERIAL_NODE_MATX_COMBINE3);
	MACRO_LINK_STR_ID("matx_combine4",RPR_MATERIAL_NODE_MATX_COMBINE4);
	MACRO_LINK_STR_ID("matx_triplanarprojection",RPR_MATERIAL_NODE_MATX_TRIPLANARPROJECTION);


	MACRO_LINK_STR_ID("toon_closure",RPR_MATERIAL_NODE_TOON_CLOSURE);
	MACRO_LINK_STR_ID("toon_ramp",RPR_MATERIAL_NODE_TOON_RAMP);
	MACRO_LINK_STR_ID("voronoi_texture",RPR_MATERIAL_NODE_VORONOI_TEXTURE);
	MACRO_LINK_STR_ID("grid_sampler",RPR_MATERIAL_NODE_GRID_SAMPLER);
	MACRO_LINK_STR_ID("blackbody",RPR_MATERIAL_NODE_BLACKBODY);
	MACRO_LINK_STR_ID("ramp",RPR_MATERIAL_NODE_RAMP);
	MACRO_LINK_STR_ID("primvar_lookup",RPR_MATERIAL_NODE_PRIMVAR_LOOKUP);

	#undef MACRO_LINK_STR_ID

	return;
}


#define RPRTOOL_MACRO_DEF_STR_MAPPER_GETSET(t,ui)\
void RPRStringIDMapper::t ## _id_to_string(ui id, std::string& strOut)\
{\
	const auto& i = m_ ## t ## _id_to_string.find(id);\
	if ( i != m_ ## t ## _id_to_string.end() )\
	{\
		strOut = i->second;\
		return;\
	}\
	strOut = "";\
	return;\
}\
ui RPRStringIDMapper::t ## _string_to_id(const std::string& strIn)\
{\
	std::string strIn_lower = std::string(strIn);\
	std::transform(strIn_lower.begin(), strIn_lower.end(), strIn_lower.begin(), [](unsigned char c){ return std::tolower(c); });\
	const auto& i = m_ ## t ## _string_to_id.find(strIn_lower);\
	if ( i != m_ ## t ## _string_to_id.end() )\
	{\
		return i->second;\
	}\
	return (ui)-1;\
}\





RPRTOOL_MACRO_DEF_STR_MAPPER_GETSET(RPRMaterialInput,rpr_material_node_input)
RPRTOOL_MACRO_DEF_STR_MAPPER_GETSET(RPRContextInput,rpr_context_info)
RPRTOOL_MACRO_DEF_STR_MAPPER_GETSET(RPRMaterialType,rpr_material_node_type)



