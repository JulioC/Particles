attribute  vec3 vPosition;
attribute  vec4 vColor;

uniform mat4 ModelView;
uniform mat4 Projection;

void main()
{
  gl_Position    = gl_ProjectionMatrix * ModelView * vec4(vPosition, 1);
  gl_FrontColor  = vColor;
  gl_TexCoord[0] = gl_MultiTexCoord0;
}

