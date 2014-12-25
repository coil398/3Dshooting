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
 72;
 0.03451;-0.03149;-0.00663;,
 0.03304;-0.03301;-0.00990;,
 0.02270;-0.00423;-0.00868;,
 0.02491;-0.00539;-0.00588;,
 0.03130;-0.03486;-0.00659;,
 0.00000;-0.02348;-0.00564;,
 0.00000;-0.02077;-0.00868;,
 0.03306;-0.03309;0.00970;,
 0.03453;-0.03154;0.00614;,
 0.02493;-0.00543;0.00545;,
 0.02273;-0.00434;0.00850;,
 0.03458;-0.03490;0.00613;,
 0.03458;-0.03486;-0.00662;,
 0.00000;-0.02092;0.00850;,
 0.00000;-0.02348;0.00562;,
 0.03133;-0.03490;0.00617;,
 0.03304;-0.03301;-0.00990;,
 0.00000;0.00027;-0.01364;,
 0.02270;-0.00423;-0.00868;,
 0.04178;0.01882;-0.00692;,
 0.04234;0.01674;-0.00987;,
 0.01404;0.02198;-0.00868;,
 0.01543;0.02329;-0.00594;,
 0.04295;0.01441;-0.00691;,
 0.04227;0.01673;0.00970;,
 0.04173;0.01882;0.00609;,
 0.01546;0.02332;0.00552;,
 0.01404;0.02208;0.00850;,
 0.04435;0.01739;0.00605;,
 0.04437;0.01741;-0.00695;,
 0.04291;0.01436;0.00608;,
 0.04234;0.01674;-0.00987;,
 0.01404;0.02198;-0.00868;,
 0.00204;0.04900;-0.00677;,
 0.00000;0.04894;-0.00987;,
 0.00000;0.04895;0.00969;,
 0.00206;0.04893;0.00640;,
 0.00000;0.05084;-0.00677;,
 0.00000;0.05080;0.00641;,
 0.00000;0.04894;-0.00987;,
 0.00000;0.00021;0.01358;,
 0.00000;-0.02077;-0.00868;,
 -0.02491;-0.00539;-0.00588;,
 -0.02270;-0.00423;-0.00868;,
 -0.03304;-0.03301;-0.00990;,
 -0.03451;-0.03149;-0.00663;,
 -0.03130;-0.03486;-0.00659;,
 -0.02273;-0.00434;0.00850;,
 -0.02493;-0.00543;0.00545;,
 -0.03453;-0.03154;0.00614;,
 -0.03306;-0.03309;0.00970;,
 -0.03458;-0.03486;-0.00662;,
 -0.03458;-0.03490;0.00613;,
 -0.03133;-0.03490;0.00617;,
 -0.02270;-0.00423;-0.00868;,
 -0.03304;-0.03301;-0.00990;,
 -0.01543;0.02329;-0.00594;,
 -0.01404;0.02198;-0.00868;,
 -0.04234;0.01674;-0.00987;,
 -0.04178;0.01882;-0.00692;,
 -0.04295;0.01441;-0.00691;,
 -0.01404;0.02208;0.00850;,
 -0.01546;0.02332;0.00552;,
 -0.04173;0.01882;0.00609;,
 -0.04227;0.01673;0.00970;,
 -0.04437;0.01741;-0.00695;,
 -0.04435;0.01739;0.00605;,
 -0.04291;0.01436;0.00608;,
 -0.04234;0.01674;-0.00987;,
 -0.01404;0.02198;-0.00868;,
 -0.00204;0.04900;-0.00677;,
 -0.00206;0.04893;0.00640;;
 
 80;
 4;0,1,2,3;,
 4;4,5,6,1;,
 4;7,8,9,10;,
 4;8,11,12,0;,
 4;8,0,3,9;,
 4;7,13,14,15;,
 4;15,14,5,4;,
 4;15,4,12,11;,
 3;16,17,18;,
 3;1,0,12;,
 3;1,12,4;,
 3;7,15,11;,
 3;7,11,8;,
 4;19,20,21,22;,
 4;23,3,2,20;,
 4;24,25,26,27;,
 4;25,28,29,19;,
 4;25,19,22,26;,
 4;24,10,9,30;,
 4;30,9,3,23;,
 4;30,23,29,28;,
 3;31,18,17;,
 3;31,17,32;,
 3;20,19,29;,
 3;20,29,23;,
 3;24,28,25;,
 3;24,30,28;,
 4;33,22,21,34;,
 4;35,27,26,36;,
 4;36,26,22,33;,
 4;36,33,37,38;,
 3;39,32,17;,
 3;34,37,33;,
 3;35,36,38;,
 3;27,35,40;,
 3;24,27,40;,
 3;10,24,40;,
 3;7,10,40;,
 3;40,13,7;,
 3;41,17,16;,
 4;42,43,44,45;,
 4;44,6,5,46;,
 4;47,48,49,50;,
 4;45,51,52,49;,
 4;48,42,45,49;,
 4;53,14,13,50;,
 4;46,5,14,53;,
 4;52,51,46,53;,
 3;54,17,55;,
 3;51,45,44;,
 3;46,51,44;,
 3;52,53,50;,
 3;49,52,50;,
 4;56,57,58,59;,
 4;58,43,42,60;,
 4;61,62,63,64;,
 4;59,65,66,63;,
 4;62,56,59,63;,
 4;67,48,47,64;,
 4;60,42,48,67;,
 4;66,65,60,67;,
 3;17,54,68;,
 3;69,17,68;,
 3;65,59,58;,
 3;60,65,58;,
 3;63,66,64;,
 3;66,67,64;,
 4;34,57,56,70;,
 4;71,62,61,35;,
 4;70,56,62,71;,
 4;38,37,70,71;,
 3;17,69,39;,
 3;70,37,34;,
 3;38,71,35;,
 3;40,35,61;,
 3;40,61,64;,
 3;40,64,47;,
 3;40,47,50;,
 3;50,13,40;,
 3;55,17,41;;
 
 MeshMaterialList {
  1;
  80;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   10.000000;
   0.500000;0.500000;0.500000;;
   1.000000;1.000000;1.000000;;
   TextureFilename {
    "Star.tga";
   }
  }
 }
 MeshTextureCoords {
  72;
  0.491308;0.158372;,
  0.491308;0.158367;,
  0.491308;0.158462;,
  0.491308;0.158459;,
  0.491308;0.158361;,
  0.491308;0.158399;,
  0.491308;0.158407;,
  0.491308;0.158369;,
  0.491308;0.158374;,
  0.491308;0.158461;,
  0.491308;0.158465;,
  0.491308;0.158363;,
  0.491308;0.158361;,
  0.491308;0.158410;,
  0.491308;0.158401;,
  0.491308;0.158363;,
  0.491308;0.158459;,
  0.491062;0.158210;,
  0.491231;0.158243;,
  0.491308;0.158539;,
  0.491308;0.158532;,
  0.491308;0.158549;,
  0.491308;0.158554;,
  0.491308;0.158525;,
  0.491308;0.158535;,
  0.491308;0.158541;,
  0.491308;0.158556;,
  0.491308;0.158552;,
  0.491308;0.158536;,
  0.491308;0.158535;,
  0.491308;0.158526;,
  0.491377;0.158087;,
  0.491166;0.158047;,
  0.491308;0.158639;,
  0.491308;0.158639;,
  0.491308;0.158642;,
  0.491308;0.158641;,
  0.491308;0.158646;,
  0.491308;0.158647;,
  0.491062;0.157846;,
  0.491308;0.158480;,
  0.491062;0.158367;,
  0.491308;0.158459;,
  0.491308;0.158462;,
  0.491308;0.158367;,
  0.491308;0.158372;,
  0.491308;0.158361;,
  0.491308;0.158465;,
  0.491308;0.158461;,
  0.491308;0.158374;,
  0.491308;0.158369;,
  0.491308;0.158361;,
  0.491308;0.158363;,
  0.491308;0.158363;,
  0.490893;0.158243;,
  0.490816;0.158459;,
  0.491308;0.158554;,
  0.491308;0.158549;,
  0.491308;0.158532;,
  0.491308;0.158539;,
  0.491308;0.158525;,
  0.491308;0.158552;,
  0.491308;0.158556;,
  0.491308;0.158541;,
  0.491308;0.158535;,
  0.491308;0.158535;,
  0.491308;0.158536;,
  0.491308;0.158526;,
  0.490746;0.158087;,
  0.490957;0.158047;,
  0.491308;0.158639;,
  0.491308;0.158641;;
 }
}
