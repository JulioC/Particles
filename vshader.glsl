uniform mat4 ModelView;
uniform mat4 Projection;

void main()
{
  gl_Position    = gl_ModelViewProjectionMatrix * gl_Vertex;
  gl_FrontColor  = gl_Color;
  gl_TexCoord[0] = gl_MultiTexCoord0;
}

