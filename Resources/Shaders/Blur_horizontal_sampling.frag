#ifdef GL_ES
precision lowp float;
#endif

#define N 25

varying vec2 v_texCoord;

uniform vec2 u_resolution;


vec4 verticalBlur(sampler2D t, vec2 p)
{
  vec4 sum = vec4(0.0);
  int count = 0;
  vec2 delta = vec2(1.0, 1.0) / u_resolution.xy;
  for (int i = -N; i <= N; i+=2)
  {
      vec2 uv;
      if (i == N)
        uv.x = p.x - float(i) * delta.x;
      else
        uv.x = p.x - (float(i) * delta.x - delta.x / 2.0);
      uv.y = p.y;
      if (uv.x < 0.0 || uv.x > 1.0)
        continue;
      sum += texture2D(t, uv);
      count ++;
  }
  return sum / float(count);
}

void main()
{
 	gl_FragColor = verticalBlur(CC_Texture0, v_texCoord);
}