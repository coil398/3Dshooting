xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 65;
 0.00000;-0.04500;-0.00000;,
 -63.63965;0.04498;63.63957;,
 -50.00136;0.04498;74.83224;,
 -34.44155;0.04498;83.14914;,
 -50.00136;0.04498;74.83224;,
 -17.55816;0.04498;88.27067;,
 -34.44155;0.04498;83.14914;,
 -17.55816;0.04498;88.27067;,
 -0.00003;0.04498;90.00000;,
 -0.00003;0.04498;90.00000;,
 17.55811;0.04498;88.27068;,
 17.55811;0.04498;88.27068;,
 34.44150;0.04498;83.14917;,
 34.44150;0.04498;83.14917;,
 50.00132;0.04498;74.83228;,
 50.00132;0.04498;74.83228;,
 63.63962;0.04498;63.63962;,
 63.63962;0.04498;63.63962;,
 74.83228;0.04498;50.00132;,
 74.83228;0.04498;50.00132;,
 83.14917;0.04498;34.44150;,
 83.14917;0.04498;34.44150;,
 88.27068;0.04498;17.55812;,
 88.27068;0.04498;17.55812;,
 90.00000;0.04498;-0.00001;,
 90.00000;0.04498;-0.00001;,
 88.27068;0.04498;-17.55813;,
 88.27068;0.04498;-17.55813;,
 83.14916;0.04498;-34.44151;,
 83.14916;0.04498;-34.44151;,
 74.83228;0.04498;-50.00132;,
 74.83228;0.04498;-50.00132;,
 63.63962;0.04498;-63.63962;,
 -74.83230;0.04498;50.00126;,
 -63.63965;0.04498;63.63957;,
 -83.14919;0.04498;34.44145;,
 -74.83230;0.04498;50.00126;,
 -88.27069;0.04498;17.55806;,
 -83.14919;0.04498;34.44145;,
 -90.00000;0.04498;-0.00009;,
 -88.27069;0.04498;17.55806;,
 -88.27066;0.04498;-17.55823;,
 -90.00000;0.04498;-0.00009;,
 -83.14912;0.04498;-34.44161;,
 -88.27066;0.04498;-17.55823;,
 -74.83220;0.04498;-50.00141;,
 -83.14912;0.04498;-34.44161;,
 -63.63953;0.04498;-63.63970;,
 -74.83220;0.04498;-50.00141;,
 -50.00122;0.04498;-74.83234;,
 -63.63953;0.04498;-63.63970;,
 -34.44139;0.04498;-83.14921;,
 -50.00122;0.04498;-74.83234;,
 -17.55799;0.04498;-88.27070;,
 -34.44139;0.04498;-83.14921;,
 0.00000;0.04498;-90.00000;,
 -17.55799;0.04498;-88.27070;,
 17.55813;0.04498;-88.27068;,
 0.00000;0.04498;-90.00000;,
 34.44151;0.04498;-83.14916;,
 17.55813;0.04498;-88.27068;,
 50.00133;0.04498;-74.83227;,
 34.44151;0.04498;-83.14916;,
 63.63962;0.04498;-63.63962;,
 50.00133;0.04498;-74.83227;;
 
 32;
 3;0,1,2;,
 3;3,0,4;,
 3;5,0,6;,
 3;7,8,0;,
 3;0,9,10;,
 3;0,11,12;,
 3;0,13,14;,
 3;0,15,16;,
 3;0,17,18;,
 3;0,19,20;,
 3;0,21,22;,
 3;0,23,24;,
 3;0,25,26;,
 3;0,27,28;,
 3;0,29,30;,
 3;0,31,32;,
 3;0,33,34;,
 3;0,35,36;,
 3;0,37,38;,
 3;0,39,40;,
 3;0,41,42;,
 3;0,43,44;,
 3;0,45,46;,
 3;0,47,48;,
 3;0,49,50;,
 3;0,51,52;,
 3;0,53,54;,
 3;0,55,56;,
 3;0,57,58;,
 3;0,59,60;,
 3;0,61,62;,
 3;0,63,64;;
 
 MeshMaterialList {
  5;
  32;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   5.000000;
   0.050000;0.050000;0.050000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "skydome_fe.bmp";
   }
  }
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.200000;0.200000;0.200000;;
   TextureFilename {
    "sd_ground1.bmp";
   }
  }
  Material {
   0.700000;0.700000;0.700000;0.990000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.300000;0.300000;0.300000;;
   TextureFilename {
    "sd_groundmask.tga";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   5.000000;
   0.050000;0.050000;0.050000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "skydome_180.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   5.000000;
   0.050000;0.050000;0.050000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "skydome_360.bmp";
   }
  }
 }
 MeshTextureCoords {
  65;
  0.500000;0.500000;,
  0.146446;0.853553;,
  0.222215;0.915735;,
  0.308658;0.961940;,
  0.222215;0.915735;,
  0.402455;0.990393;,
  0.308658;0.961940;,
  0.402455;0.990393;,
  0.500000;1.000000;,
  0.500000;1.000000;,
  0.597545;0.990393;,
  0.597545;0.990393;,
  0.691342;0.961940;,
  0.691342;0.961940;,
  0.777785;0.915735;,
  0.777785;0.915735;,
  0.853553;0.853553;,
  0.853553;0.853553;,
  0.915735;0.777785;,
  0.915735;0.777785;,
  0.961940;0.691342;,
  0.961940;0.691342;,
  0.990393;0.597545;,
  0.990393;0.597545;,
  1.000000;0.500000;,
  1.000000;0.500000;,
  0.990393;0.402455;,
  0.990393;0.402455;,
  0.961940;0.308658;,
  0.961940;0.308658;,
  0.915735;0.222215;,
  0.915735;0.222215;,
  0.853553;0.146447;,
  0.084265;0.777785;,
  0.146446;0.853553;,
  0.038060;0.691341;,
  0.084265;0.777785;,
  0.009607;0.597545;,
  0.038060;0.691341;,
  0.000000;0.499999;,
  0.009607;0.597545;,
  0.009607;0.402454;,
  0.000000;0.499999;,
  0.038060;0.308658;,
  0.009607;0.402454;,
  0.084266;0.222214;,
  0.038060;0.308658;,
  0.146447;0.146446;,
  0.084266;0.222214;,
  0.222215;0.084265;,
  0.146447;0.146446;,
  0.308659;0.038060;,
  0.222215;0.084265;,
  0.402456;0.009607;,
  0.308659;0.038060;,
  0.500000;0.000000;,
  0.402456;0.009607;,
  0.597545;0.009607;,
  0.500000;0.000000;,
  0.691342;0.038060;,
  0.597545;0.009607;,
  0.777785;0.084265;,
  0.691342;0.038060;,
  0.853553;0.146447;,
  0.777785;0.084265;;
 }
 MeshVertexColors {
  65;
  0;1.000000;1.000000;1.000000;1.000000;,
  1;1.000000;1.000000;1.000000;1.000000;,
  2;1.000000;1.000000;1.000000;1.000000;,
  3;1.000000;1.000000;1.000000;1.000000;,
  4;1.000000;1.000000;1.000000;1.000000;,
  5;1.000000;1.000000;1.000000;1.000000;,
  6;1.000000;1.000000;1.000000;1.000000;,
  7;1.000000;1.000000;1.000000;1.000000;,
  8;1.000000;1.000000;1.000000;1.000000;,
  9;1.000000;1.000000;1.000000;1.000000;,
  10;1.000000;1.000000;1.000000;1.000000;,
  11;1.000000;1.000000;1.000000;1.000000;,
  12;1.000000;1.000000;1.000000;1.000000;,
  13;1.000000;1.000000;1.000000;1.000000;,
  14;1.000000;1.000000;1.000000;1.000000;,
  15;1.000000;1.000000;1.000000;1.000000;,
  16;1.000000;1.000000;1.000000;1.000000;,
  17;1.000000;1.000000;1.000000;1.000000;,
  18;1.000000;1.000000;1.000000;1.000000;,
  19;1.000000;1.000000;1.000000;1.000000;,
  20;1.000000;1.000000;1.000000;1.000000;,
  21;1.000000;1.000000;1.000000;1.000000;,
  22;1.000000;1.000000;1.000000;1.000000;,
  23;1.000000;1.000000;1.000000;1.000000;,
  24;1.000000;1.000000;1.000000;1.000000;,
  25;1.000000;1.000000;1.000000;1.000000;,
  26;1.000000;1.000000;1.000000;1.000000;,
  27;1.000000;1.000000;1.000000;1.000000;,
  28;1.000000;1.000000;1.000000;1.000000;,
  29;1.000000;1.000000;1.000000;1.000000;,
  30;1.000000;1.000000;1.000000;1.000000;,
  31;1.000000;1.000000;1.000000;1.000000;,
  32;1.000000;1.000000;1.000000;1.000000;,
  33;1.000000;1.000000;1.000000;1.000000;,
  34;1.000000;1.000000;1.000000;1.000000;,
  35;1.000000;1.000000;1.000000;1.000000;,
  36;1.000000;1.000000;1.000000;1.000000;,
  37;1.000000;1.000000;1.000000;1.000000;,
  38;1.000000;1.000000;1.000000;1.000000;,
  39;1.000000;1.000000;1.000000;1.000000;,
  40;1.000000;1.000000;1.000000;1.000000;,
  41;1.000000;1.000000;1.000000;1.000000;,
  42;1.000000;1.000000;1.000000;1.000000;,
  43;1.000000;1.000000;1.000000;1.000000;,
  44;1.000000;1.000000;1.000000;1.000000;,
  45;1.000000;1.000000;1.000000;1.000000;,
  46;1.000000;1.000000;1.000000;1.000000;,
  47;1.000000;1.000000;1.000000;1.000000;,
  48;1.000000;1.000000;1.000000;1.000000;,
  49;1.000000;1.000000;1.000000;1.000000;,
  50;1.000000;1.000000;1.000000;1.000000;,
  51;1.000000;1.000000;1.000000;1.000000;,
  52;1.000000;1.000000;1.000000;1.000000;,
  53;1.000000;1.000000;1.000000;1.000000;,
  54;1.000000;1.000000;1.000000;1.000000;,
  55;1.000000;1.000000;1.000000;1.000000;,
  56;1.000000;1.000000;1.000000;1.000000;,
  57;1.000000;1.000000;1.000000;1.000000;,
  58;1.000000;1.000000;1.000000;1.000000;,
  59;1.000000;1.000000;1.000000;1.000000;,
  60;1.000000;1.000000;1.000000;1.000000;,
  61;1.000000;1.000000;1.000000;1.000000;,
  62;1.000000;1.000000;1.000000;1.000000;,
  63;1.000000;1.000000;1.000000;1.000000;,
  64;1.000000;1.000000;1.000000;1.000000;;
 }
}
