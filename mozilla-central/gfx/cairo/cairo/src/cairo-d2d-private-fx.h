#if 0
//
// FX Version: fx_4_0
// Child effect (requires effect pool): false
//
// 1 local buffer(s)
//
cbuffer cb0
{
    float4  QuadDesc;                   // Offset:    0, size:   16
    float4  TexCoords;                  // Offset:   16, size:   16
}

//
// 2 local object(s)
//
Texture2D tex;
SamplerState sSampler
{
    Texture  = tex;
    AddressU = uint(CLAMP /* 3 */);
    AddressV = uint(CLAMP /* 3 */);
};

//
// 1 technique(s)
//
technique10 SampleTexture
{
    pass P0
    {
        VertexShader = asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.27.952.3022
            //
            //
            // Buffer Definitions: 
            //
            // cbuffer cb0
            // {
            //
            //   float4 QuadDesc;                   // Offset:    0 Size:    16
            //   float4 TexCoords;                  // Offset:   16 Size:    16
            //
            // }
            //
            //
            // Resource Bindings:
            //
            // Name                                 Type  Format         Dim Slot Elements
            // ------------------------------ ---------- ------- ----------- ---- --------
            // cb0                               cbuffer      NA          NA    0        1
            //
            //
            //
            // Input signature:
            //
            // Name                 Index   Mask Register SysValue Format   Used
            // -------------------- ----- ------ -------- -------- ------ ------
            // POSITION                 0   xyz         0     NONE  float   xy  
            //
            //
            // Output signature:
            //
            // Name                 Index   Mask Register SysValue Format   Used
            // -------------------- ----- ------ -------- -------- ------ ------
            // SV_Position              0   xyzw        0      POS  float   xyzw
            // TEXCOORD                 0   xy          1     NONE  float   xy  
            //
            //
            // Constant buffer to DX9 shader constant mappings:
            //
            // Target Reg Buffer  Start Reg # of Regs        Data Conversion
            // ---------- ------- --------- --------- ----------------------
            // c1         cb0             0         2  ( FLT, FLT, FLT, FLT)
            //
            //
            // Runtime generated constant mappings:
            //
            // Target Reg                               Constant Description
            // ---------- --------------------------------------------------
            // c0                              Vertex Shader position offset
            //
            //
            // Level9 shader bytecode:
            //
                vs_2_x
                def c3, 0, 1, 0, 0
                dcl_texcoord v0
                mad oT0.xy, v0, c2.zwzw, c2
                mad r0.x, v0.x, c1.z, c1.x
                mad r0.y, v0.y, c1.w, c1.y
                add oPos.xy, r0, c0
                mov oPos.zw, c3.xyxy
            
            // approximately 5 instruction slots used
            vs_4_0
            dcl_constantbuffer cb0[2], immediateIndexed
            dcl_input v0.xy
            dcl_output_siv o0.xyzw, position
            dcl_output o1.xy
            mad o0.xy, v0.xyxx, cb0[0].zwzz, cb0[0].xyxx
            mov o0.zw, l(0,0,0,1.000000)
            mad o1.xy, v0.xyxx, cb0[1].zwzz, cb0[1].xyxx
            ret 
            // Approximately 4 instruction slots used
                    
        };
        GeometryShader = NULL;
        PixelShader = asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.27.952.3022
            //
            //
            // Resource Bindings:
            //
            // Name                                 Type  Format         Dim Slot Elements
            // ------------------------------ ---------- ------- ----------- ---- --------
            // sSampler                          sampler      NA          NA    0        1
            // tex                               texture  float4          2d    0        1
            //
            //
            //
            // Input signature:
            //
            // Name                 Index   Mask Register SysValue Format   Used
            // -------------------- ----- ------ -------- -------- ------ ------
            // SV_Position              0   xyzw        0      POS  float       
            // TEXCOORD                 0   xy          1     NONE  float   xy  
            //
            //
            // Output signature:
            //
            // Name                 Index   Mask Register SysValue Format   Used
            // -------------------- ----- ------ -------- -------- ------ ------
            // SV_Target                0   xyzw        0   TARGET  float   xyzw
            //
            //
            // Sampler/Resource to DX9 shader sampler mappings:
            //
            // Target Sampler Source Sampler  Source Resource
            // -------------- --------------- ----------------
            // s0             s0              t0               
            //
            //
            // Level9 shader bytecode:
            //
                ps_2_x
                dcl t0.xy
                dcl_2d s0
                texld r0, t0, s0
                mov oC0, r0
            
            // approximately 2 instruction slots used (1 texture, 1 arithmetic)
            ps_4_0
            dcl_sampler s0, mode_default
            dcl_resource_texture2d (float,float,float,float) t0
            dcl_input_ps linear v1.xy
            dcl_output o0.xyzw
            sample o0.xyzw, v1.xyxx, t0.xyzw, s0
            ret 
            // Approximately 2 instruction slots used
                    
        };
    }

}

#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 235,  24, 
    238,   6,  37, 230, 191, 228, 
     58,  61,  41, 219,  70, 130, 
     61,  51,   1,   0,   0,   0, 
    187,   8,   0,   0,   1,   0, 
      0,   0,  36,   0,   0,   0, 
     70,  88,  49,  48, 143,   8, 
      0,   0,   1,  16, 255, 254, 
      1,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  79,   7, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,  99,  98, 
     48,   0, 102, 108, 111,  97, 
    116,  52,   0,   8,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0,  16,   0,   0, 
      0,  16,   0,   0,   0,  16, 
      0,   0,   0,  10,  33,   0, 
      0,  81, 117,  97, 100,  68, 
    101, 115,  99,   0,  84, 101, 
    120,  67, 111, 111, 114, 100, 
    115,   0,  84, 101, 120, 116, 
    117, 114, 101,  50,  68,   0, 
     62,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0, 116, 101, 
    120,   0,  83,  97, 109, 112, 
    108, 101, 114,  83, 116,  97, 
    116, 101,   0, 104,   0,   0, 
      0,   2,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  21,   0,   0, 
      0, 115,  83,  97, 109, 112, 
    108, 101, 114,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,  83,  97, 
    109, 112, 108, 101,  84, 101, 
    120, 116, 117, 114, 101,   0, 
     80,  48,   0, 172,   3,   0, 
      0,  68,  88,  66,  67, 247, 
    105,  31, 113, 120,  95,  58, 
     12, 207, 141,  45,  76, 175, 
     59, 223,  25,   1,   0,   0, 
      0, 172,   3,   0,   0,   6, 
      0,   0,   0,  56,   0,   0, 
      0, 248,   0,   0,   0, 188, 
      1,   0,   0,  56,   2,   0, 
      0,  32,   3,   0,   0,  84, 
      3,   0,   0,  65, 111, 110, 
     57, 184,   0,   0,   0, 184, 
      0,   0,   0,   0,   2, 254, 
    255, 132,   0,   0,   0,  52, 
      0,   0,   0,   1,   0,  36, 
      0,   0,   0,  48,   0,   0, 
      0,  48,   0,   0,   0,  36, 
      0,   1,   0,  48,   0,   0, 
      0,   0,   0,   2,   0,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   1,   2, 254, 
    255,  81,   0,   0,   5,   3, 
      0,  15, 160,   0,   0,   0, 
      0,   0,   0, 128,  63,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  31,   0,   0,   2,   5, 
      0,   0, 128,   0,   0,  15, 
    144,   4,   0,   0,   4,   0, 
      0,   3, 224,   0,   0, 228, 
    144,   2,   0, 238, 160,   2, 
      0, 228, 160,   4,   0,   0, 
      4,   0,   0,   1, 128,   0, 
      0,   0, 144,   1,   0, 170, 
    160,   1,   0,   0, 160,   4, 
      0,   0,   4,   0,   0,   2, 
    128,   0,   0,  85, 144,   1, 
      0, 255, 160,   1,   0,  85, 
    160,   2,   0,   0,   3,   0, 
      0,   3, 192,   0,   0, 228, 
    128,   0,   0, 228, 160,   1, 
      0,   0,   2,   0,   0,  12, 
    192,   3,   0,  68, 160, 255, 
    255,   0,   0,  83,  72,  68, 
     82, 188,   0,   0,   0,  64, 
      0,   1,   0,  47,   0,   0, 
      0,  89,   0,   0,   4,  70, 
    142,  32,   0,   0,   0,   0, 
      0,   2,   0,   0,   0,  95, 
      0,   0,   3,  50,  16,  16, 
      0,   0,   0,   0,   0, 103, 
      0,   0,   4, 242,  32,  16, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0, 101,   0,   0, 
      3,  50,  32,  16,   0,   1, 
      0,   0,   0,  50,   0,   0, 
     11,  50,  32,  16,   0,   0, 
      0,   0,   0,  70,  16,  16, 
      0,   0,   0,   0,   0, 230, 
    138,  32,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  70, 
    128,  32,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  54, 
      0,   0,   8, 194,  32,  16, 
      0,   0,   0,   0,   0,   2, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0, 128, 
     63,  50,   0,   0,  11,  50, 
     32,  16,   0,   1,   0,   0, 
      0,  70,  16,  16,   0,   0, 
      0,   0,   0, 230, 138,  32, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0,  70, 128,  32, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0,  62,   0,   0, 
      1,  83,  84,  65,  84, 116, 
      0,   0,   0,   4,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   3,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  82, 
     68,  69,  70, 224,   0,   0, 
      0,   1,   0,   0,   0,  64, 
      0,   0,   0,   1,   0,   0, 
      0,  28,   0,   0,   0,   0, 
      4, 254, 255,   0, 129,   0, 
      0, 174,   0,   0,   0,  60, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0,   0,   0,   0, 
      0,  99,  98,  48,   0,  60, 
      0,   0,   0,   2,   0,   0, 
      0,  88,   0,   0,   0,  32, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0, 136, 
      0,   0,   0,   0,   0,   0, 
      0,  16,   0,   0,   0,   2, 
      0,   0,   0, 148,   0,   0, 
      0,   0,   0,   0,   0, 164, 
      0,   0,   0,  16,   0,   0, 
      0,  16,   0,   0,   0,   2, 
      0,   0,   0, 148,   0,   0, 
      0,   0,   0,   0,   0,  81, 
    117,  97, 100,  68, 101, 115, 
     99,   0, 171, 171, 171,   1, 
      0,   3,   0,   1,   0,   4, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  84, 101, 120, 
     67, 111, 111, 114, 100, 115, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  55,  46,  57, 
     53,  50,  46,  51,  48,  50, 
     50,   0, 171,  73,  83,  71, 
     78,  44,   0,   0,   0,   1, 
      0,   0,   0,   8,   0,   0, 
      0,  32,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   3,   0,   0,   0,   0, 
      0,   0,   0,   7,   3,   0, 
      0,  80,  79,  83,  73,  84, 
     73,  79,  78,   0, 171, 171, 
    171,  79,  83,  71,  78,  80, 
      0,   0,   0,   2,   0,   0, 
      0,   8,   0,   0,   0,  56, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   3, 
      0,   0,   0,   0,   0,   0, 
      0,  15,   0,   0,   0,  68, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   3, 
      0,   0,   0,   1,   0,   0, 
      0,   3,  12,   0,   0,  83, 
     86,  95,  80, 111, 115, 105, 
    116, 105, 111, 110,   0,  84, 
     69,  88,  67,  79,  79,  82, 
     68,   0, 171, 171, 171, 195, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   2, 
      0,   0,   0,   0,   0,   0, 
      0, 188,   2,   0,   0,  68, 
     88,  66,  67,  90,  17, 243, 
     62, 104,  14,   0,  40,  49, 
     70, 150,  92,  77,   1, 115, 
    141,   1,   0,   0,   0, 188, 
      2,   0,   0,   6,   0,   0, 
      0,  56,   0,   0,   0, 164, 
      0,   0,   0,  16,   1,   0, 
      0, 140,   1,   0,   0,  48, 
      2,   0,   0, 136,   2,   0, 
      0,  65, 111, 110,  57, 100, 
      0,   0,   0, 100,   0,   0, 
      0,   0,   2, 255, 255,  60, 
      0,   0,   0,  40,   0,   0, 
      0,   0,   0,  40,   0,   0, 
      0,  40,   0,   0,   0,  40, 
      0,   1,   0,  36,   0,   0, 
      0,  40,   0,   0,   0,   0, 
      0,   1,   2, 255, 255,  31, 
      0,   0,   2,   0,   0,   0, 
    128,   0,   0,   3, 176,  31, 
      0,   0,   2,   0,   0,   0, 
    144,   0,   8,  15, 160,  66, 
      0,   0,   3,   0,   0,  15, 
    128,   0,   0, 228, 176,   0, 
      8, 228, 160,   1,   0,   0, 
      2,   0,   8,  15, 128,   0, 
      0, 228, 128, 255, 255,   0, 
      0,  83,  72,  68,  82, 100, 
      0,   0,   0,  64,   0,   0, 
      0,  25,   0,   0,   0,  90, 
      0,   0,   3,   0,  96,  16, 
      0,   0,   0,   0,   0,  88, 
     24,   0,   4,   0, 112,  16, 
      0,   0,   0,   0,   0,  85, 
     85,   0,   0,  98,  16,   0, 
      3,  50,  16,  16,   0,   1, 
      0,   0,   0, 101,   0,   0, 
      3, 242,  32,  16,   0,   0, 
      0,   0,   0,  69,   0,   0, 
      9, 242,  32,  16,   0,   0, 
      0,   0,   0,  70,  16,  16, 
      0,   1,   0,   0,   0,  70, 
    126,  16,   0,   0,   0,   0, 
      0,   0,  96,  16,   0,   0, 
      0,   0,   0,  62,   0,   0, 
      1,  83,  84,  65,  84, 116, 
      0,   0,   0,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  82, 
     68,  69,  70, 156,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   2,   0,   0, 
      0,  28,   0,   0,   0,   0, 
      4, 255, 255,   0, 129,   0, 
      0, 105,   0,   0,   0,  92, 
      0,   0,   0,   3,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0,   0,   0,   0, 
      0, 101,   0,   0,   0,   2, 
      0,   0,   0,   5,   0,   0, 
      0,   4,   0,   0,   0, 255, 
    255, 255, 255,   0,   0,   0, 
      0,   1,   0,   0,   0,  12, 
      0,   0,   0, 115,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    116, 101, 120,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  57,  46,  50, 
     55,  46,  57,  53,  50,  46, 
     51,  48,  50,  50,   0, 171, 
    171,  73,  83,  71,  78,  80, 
      0,   0,   0,   2,   0,   0, 
      0,   8,   0,   0,   0,  56, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   3, 
      0,   0,   0,   0,   0,   0, 
      0,  15,   0,   0,   0,  68, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   3, 
      0,   0,   0,   1,   0,   0, 
      0,   3,   3,   0,   0,  83, 
     86,  95,  80, 111, 115, 105, 
    116, 105, 111, 110,   0,  84, 
     69,  88,  67,  79,  79,  82, 
     68,   0, 171, 171, 171,  79, 
     83,  71,  78,  44,   0,   0, 
      0,   1,   0,   0,   0,   8, 
      0,   0,   0,  32,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   3,   0,   0, 
      0,   0,   0,   0,   0,  15, 
      0,   0,   0,  83,  86,  95, 
     84,  97, 114, 103, 101, 116, 
      0, 171, 171, 135,   4,   0, 
      0,   0,   0,   0,   0,   4, 
      0,   0,   0,  32,   0,   0, 
      0,   0,   0,   0,   0,   2, 
      0,   0,   0, 255, 255, 255, 
    255,   0,   0,   0,   0,  43, 
      0,   0,   0,  15,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  52,   0,   0, 
      0,  15,   0,   0,   0,   0, 
      0,   0,   0,  16,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 100,   0,   0,   0,  72, 
      0,   0,   0,   0,   0,   0, 
      0, 255, 255, 255, 255,   0, 
      0,   0,   0, 145,   0,   0, 
      0, 117,   0,   0,   0,   0, 
      0,   0,   0, 255, 255, 255, 
    255,   3,   0,   0,   0,  55, 
      0,   0,   0,   0,   0,   0, 
      0,   2,   0,   0,   0, 100, 
      0,   0,   0,  46,   0,   0, 
      0,   0,   0,   0,   0,   1, 
      0,   0,   0, 154,   0,   0, 
      0,  47,   0,   0,   0,   0, 
      0,   0,   0,   1,   0,   0, 
      0, 166,   0,   0,   0,   0, 
      0,   0,   0, 178,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0, 192,   0,   0, 
      0,   3,   0,   0,   0,   0, 
      0,   0,   0,   6,   0,   0, 
      0,   0,   0,   0,   0,   7, 
      0,   0,   0, 115,   4,   0, 
      0,   8,   0,   0,   0,   0, 
      0,   0,   0,   1,   0,   0, 
      0, 123,   4,   0,   0,   7, 
      0,   0,   0,   0,   0,   0, 
      0,   7,   0,   0,   0,  71, 
      7,   0,   0
};
