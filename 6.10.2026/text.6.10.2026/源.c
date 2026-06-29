//#include <stdio.h>
//int main() {
//    int i, j, a[1000] = { 0 }, count = 0;
//
//    for (i = 2; i <= 1000; i++) {
//        a[i - 2] = i;
//    }
//
//    for (i = 0; i < 500; i++) {
//        if (a[i] != 0) {                     
//            for (j = i + 1; j < 1000; j++) {
//                if (a[j] % a[i] == 0) {     
//                    a[j] = 0;
//                }
//            }
//        }
//    }
//
//    for (i = 0; i < 1000; i++) {
//        if (a[i] != 0) {
//            printf("%4d", a[i]);
//            count++;
//            if (count % 8 == 0) {            
//                printf("\n");
//            }
//        }
//    }
//    printf("\n");
//
//    return 0;
//Shader "Custom/IrisWipe"
{
    Properties
    {
        _Radius("ÕöÑÛ³Ì¶È", Range(0, 1.5)) = 0
        _Aspect("ÍÖÔ²±â¶È", Range(0.2, 1.2)) = 0.55
    }
        SubShader
    {
        Tags { "Queue" = "Overlay" "RenderType" = "Transparent" }
        Blend SrcAlpha OneMinusSrcAlpha
        ZWrite Off

        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            float _Radius;
            float _Aspect;

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f
            {
                float4 vertex : SV_POSITION;
                float2 uv : TEXCOORD0;
            };

            v2f vert(appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = v.uv;
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                float2 center = float2(0.5, 0.5);
                float2 diff = i.uv - center;
                float ellipseDist = length(float2(diff.x, diff.y / _Aspect));
                float iris = 1.0 - saturate(step(ellipseDist, _Radius));
                return float4(0, 0, 0, iris);
            }
            ENDCG
        }
    }
}