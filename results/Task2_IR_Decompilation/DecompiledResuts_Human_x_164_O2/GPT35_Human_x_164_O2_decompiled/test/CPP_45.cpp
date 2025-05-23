float triangle_areaff(float arg0, float arg1) {
    float var0 = arg0 * arg1;
    float var1 = var0 * 0.5;
    return var1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
