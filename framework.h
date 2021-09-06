#define framework

#include <string>
#include <cmath>

// The Fucking Problem:
//
//



// Working on :

// Segment collision ''
// normal ''
// ypar and normal  ''
// ypar and xpar    ''
// xpar and normal  ''
// xpar and xpar   ''
// ypar and ypar   ''

// (Maybe has been completely fixed, but, idk )  Something is wrong with how i determined the calculation selection aalgorithn for tyhe segment intetrsection algorithm







namespace debug
{
    class log
    {
    private:
        static const int ukuran = 10;
        int position = 0;
        std::string masalah[ukuran];
    public:

        void add(std::string apa)
        {
            if(position < ukuran)
            {
                masalah[position] = apa;
                position++;
            }else if(position >= ukuran){}else{}
        }
        void pop()
        {
            position--;
            masalah[position] = "";
        }
        void display()
        {
            for(int n = 0; n < position + 1; n++)
            {
                std::cout << masalah[position] << std::endl;
            }
        }
    };

    static log daftar_masalah;
}

namespace alg
{


    float com_max(float a, float b, float c, float d)
    {

        float angka[4] = {a, b, c, d};
        float banyak = 4;

        float besar = a;



            for(int n = 0; n < banyak; n++)
            {
                if(besar < angka[n])
                {
                    besar = angka[n];
                }else{}



            }

        return besar;
    }

    float com_min(float a, float b, float c, float d)
    {

        float angka[4] = {a, b, c, d};
        float banyak = 4;

        float kecil = a;



            for(int n = 0; n < banyak; n++)
            {
                if(kecil > angka[n])
                {
                    kecil = angka[n];
                }else{}



            }

        return kecil;
    }




    bool isinmiddle(float awal, float b, float akhir)
    {

        float minimal = std::fmin(awal, akhir);
        float maksimal = std::fmax(awal, akhir);

        if((minimal <= b) && (b <= maksimal)){return true;}else{return false;}


    }





}


namespace math
{
    bool isequal(float a, float b, double tolerance = 0.001)
    {

        float different = std::fabs(a - b);

        if(different <= tolerance){return true;}
        else{return false;}
    }



}


namespace basic
{
    struct point{float x = 0; float y = 0; bool invalid = false;};
    struct square
    {
        private:
            point vertices[4];
            point anchor;
            float sizex;
            float sizey;

        public:

            square(float x, float y, float six, float siy)
            {
                anchor.x = x;
                anchor.y = y;
                sizex = six;
                sizey = siy;

                vertices[0] = {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
                vertices[1] = {(anchor.x + sizex / 2), (anchor.y - sizey / 2)};
                vertices[2] = {(anchor.x + sizex / 2), (anchor.y + sizey / 2)};
                vertices[3] = {(anchor.x - sizex / 2), (anchor.y + sizey / 2)};

            }

            void update()
            {
                vertices[0] = {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
                vertices[1] = {(anchor.x + sizex / 2), (anchor.y - sizey / 2)};
                vertices[2] = {(anchor.x + sizex / 2), (anchor.y + sizey / 2)};
                vertices[3] = {(anchor.x - sizex / 2), (anchor.y + sizey / 2)};

            }

            sf::Vector2f posisisfml()
            {
                    return {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
            }

            sf::Vector2f ukuransfml()
            {
                return {sizex, sizey};
            }

            point& pusat = anchor;
            float& ukuranx = sizex;
            float& ukurany = sizey;


            point& sudut1 = vertices[0];
            point& sudut2 = vertices[1];
            point& sudut3 = vertices[2];
            point& sudut4 = vertices[3];

    };




    struct segment{

        point a; point b;  // Lets just say that a is 1 and b is 2

        float slope;
        float constant;
        bool isParalleltoX = false;
        bool isParalleltoY = false;
        bool isUpdated = false;

        segment(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0)   // Konstrukto (Fungis inisisasi)
        {
            a.x = x1;a.y = y1; b.x = x2; b.y = y2; // Assigning the segment ends point coordinates

            if(y2 == y1 && x2 != x1){isParalleltoX = true;}    // Ruas sejajar dengan sumbu x
            else if(y2 != y1 && x2 == x1){isParalleltoY = true;}// Ruas sejajar dengan sumbu y
            else                                              // Ruas bioasa biasa aja
            {
                slope = (y2 - y1) / (x2 - x1);
                constant = y1 - slope * x1;
            }

            isUpdated = true;   // Mengatakan ke komputer bahwa ruas garis ini telah di update
        }

        void update()
        {
            float& x1 = a.x;
            float& y1 = a.y;   // Adaptor untuk baris kode yang di kopi paste dari bagian di atas, saya ,ales nulis lagi :)
            float& x2 = b.x;
            float& y2 = b.y;

            if(y2 == y1 && x2 != x1){isParalleltoX = true;}    // Ruas sejajat dengan sumbu x
            else if(y2 != y1 && x2 == x1){isParalleltoY = true;} // Ruas sejajar dengan sumbu y
            else                                              // Ruas biasa biasa aja
            {
                slope = (y2 - y1) / (x2 - x1);
                constant = y1 - slope * x1;
            }

            isUpdated = true; // Mengatakan ke program bahwa ruas ini telah  di upodate

        }

        void change_a(float r, float s)
        {
            a.x = r;
            a.y = s;
            isUpdated = false;   // Karena posisi diganti, belum di update

        }
        void change_b(float r, float s)
        {
            b.x = r;
            b.y = s;
            isUpdated = false; // Karena posisi di ganti, belum di update
        }
        bool isNew(){return isUpdated;}




    };

    struct circle
    {
        private:

            float radius;
            float diameter;
            point anchor;

        public:

            circle(float x, float y, float r)
            {
                anchor.x = x; anchor.y = y; radius = r; diameter = radius * 2;
            }

            float& rad = radius;
            float& dia = diameter;
            float& x = anchor.x;
            float& y = anchor.y;

    };
};

namespace collision
{

    using namespace basic;

    bool aabb(square kot1, square kot2)
    {
        /*
            point& sudut1 = vertices[0];
            point& sudut2 = vertices[1];
            point& sudut3 = vertices[2];
            point& sudut4 = vertices[3];

            point& pusat = anchor;
            float& ukuranx = sizex;
            float& ukurany = sizey;

        */

        float& a1 = kot1.sudut1.x;
        float& a2 = kot1.sudut2.x;
        float& b1 = kot1.sudut1.y;
        float& b4 = kot1.sudut4.y;

        float& c1 = kot2.sudut1.x;
        float& c2 = kot2.sudut2.x;
        float& d1 = kot2.sudut1.y;
        float& d4 = kot2.sudut4.y;



        if(( alg::com_max(std::fabs(b1 - d4), std::fabs(b1 - d1), std::fabs(b4 - d1), std::fabs(b4 - d4)) <= (std::fabs(b4 - b1) + std::fabs(d4 -d1))) && (alg::com_max(std::fabs(a1 - c2), std::fabs(a1 - c1), std::fabs(a2 - c2), std::fabs(a2 - c1)) <= (std::fabs(a2 - a1) + std::fabs(c2 - c1))) )

            {return true;}

                else{return false;}



    }


    point intersect(basic::segment gar1, basic::segment gar2)
    {
        point intersection;
        if(!gar1.isNew()){gar1.update();}   // Memperbarui keadaan garis, perlu untuk pemrosesan berikutnya
        if(!gar2.isNew()){gar2.update();}

        if(!gar1.isParalleltoX && !gar1.isParalleltoY && !gar2.isParalleltoX && !gar2.isParalleltoY)   // Jika garis normal
        {
            if(gar1.slope != gar2.slope){
            intersection.x = (gar2.constant - gar1.constant) / (gar1.slope - gar2.slope);
            intersection.y = gar1.slope * intersection.x + gar1.constant;}

            else{
                intersection.invalid = true;
            }
            return intersection;

            debug::daftar_masalah.add("Garis Normal");
        }else
        {
            if((gar1.isParalleltoX || gar2.isParalleltoX) && (!gar1.isParalleltoX || !gar2.isParalleltoY) && (!gar2.isParalleltoX || !gar1.isParalleltoY))    // Jika salah satu garis sejajar dengan sumbu x
            {
                segment xpar;
                segment normal;


                float b;
                float a;
                if(gar1.isParalleltoX){xpar = gar1; normal = gar2;}
                else if(gar2.isParalleltoX){xpar = gar2; normal = gar1;}

                b = xpar.a.y;
                a = (b - normal.constant) / normal.slope;std::cout << "here" << std::endl;

                intersection.x = a;
                intersection.y = b;

                return intersection;
                debug::daftar_masalah.add("Salah satu garis sejajar dengan sumbu x");

             }else if((gar1.isParalleltoY || gar2.isParalleltoY) && !(gar1.isParalleltoX || gar2.isParalleltoY) && !(gar2.isParalleltoX || gar1.isParalleltoY))  // JIka salah satu garis sejajar dengan sumbyu y
             {
                segment ypar;
                segment normal;


                float b;
                float a;
                if(gar1.isParalleltoY){ypar = gar1; normal = gar2;}
                else if(gar2.isParalleltoY){ypar = gar2; normal = gar1;}

                a = ypar.a.x;
                b = normal.slope * a + normal.constant;

                intersection.x = a;
                intersection.y = b;

                return intersection;
             }else if((gar1.isParalleltoX && gar2.isParalleltoY) || (gar1.isParalleltoY && gar2.isParalleltoX))  // Jika salah satu paralel dengan sumbu x dan yang satunt paralel dengan sumbu y
             {
                 segment ypar;
                 segment xpar;

                 if(gar1.isParalleltoX){xpar = gar1; ypar = gar2;}      // Menentukan garis mana yang sejajar dengan sumbu x dan yang mana yang sejajar dengabh sumbu y
                 else if(gar1.isParalleltoY){xpar = gar2; ypar = gar1;}

                 intersection.x = ypar.a.x;
                 intersection.y = xpar.a.y;



                 return intersection;
             }else if(gar1.isParalleltoX && gar2.isParalleltoX)    //JIka kedua garis sejajar dengn sumbu x
             {
                 if(gar1.a.y == gar2.a.y) // JIka kedua garis berada pada posoisi y yang sama, berarti dapt diketahui lokasi tabrakannya
                 {
                     float x;
                     float y = gar2.a.y;
                     float minx = alg::com_min(gar1.a.x, gar1.b.x, gar2.a.x, gar2.b.x);
                     float maxx = alg::com_max(gar1.a.x, gar1.b.x, gar2.a.x, gar2.b.x);
                     x = minx + (maxx - minx) / 2;
                     intersection.x = x;
                     intersection.y = y;
                     return intersection;

                 }else // Jika kedau garis berada pada popsisi y yang berbeda, berarti tak dapat diketahui temp[at tabtraknnya, karena tidak mungkin tabrakan
                 {
                     intersection.invalid = true;
                     return intersection;
                 }
             }
             else if(gar1.isParalleltoY && gar2.isParalleltoY)  // Kedua garis sejajar dengan sumbu y
             {
                 if(gar1.a.x == gar2.a.x) // JIka kedua garis berada pada posoisi x yang sama, berarti dapt diketahui lokasi tabrakannya
                 {
                     float x = gar2.a.x;
                     float y;
                     float miny = alg::com_min(gar1.a.y, gar1.b.y, gar2.a.y, gar2.b.y);
                     float maxy = alg::com_max(gar1.a.y, gar1.b.y, gar2.a.y, gar2.b.y);
                     y = miny + (maxy - miny) / 2;
                     intersection.x = x;
                     intersection.y = y;
                     return intersection;

                 }else // Jika kedau garis berada pada popsisi x yang berbeda, berarti tak dapat diketahui temp[at tabtraknnya, karena tidak mungkin tabrakan
                 {
                     intersection.invalid = true;
                     return intersection;
                 }
             }else
             {
                 debug::daftar_masalah.add("Anjayyyyyyy Bangsat !!!");
                 intersection.invalid = true;
                 return intersection;
             }


        }

    }

    bool isinsegment(point titik, segment gar)
    {
        if(!titik.invalid){
        if(!gar.isParalleltoX && !gar.isParalleltoY)
        {

            if(math::isequal(titik.y, titik.x * gar.slope + gar.constant) && alg::isinmiddle(gar.a.x, titik.x, gar.b.x) && alg::isinmiddle(gar.a.y, titik.y, gar.b.y)){return true;}
            else{return false;}

        }else if(gar.isParalleltoX)
        {
            if(titik.y == gar.a.y && alg::isinmiddle(gar.a.x, titik.x, gar.b.x)){return true;}
            else{return false;}

        }else if(gar.isParalleltoY)
        {
            if(titik.x == gar.a.x && alg::isinmiddle(gar.a.y, titik.y, gar.b.y)){return true;}
            else{return false;}
        }

        else{return false;}
    }else if(titik.invalid){return false;}
    else{return false;}
    }



    bool segment_collision(basic::segment gar1, basic::segment gar2)
    {
        point tabrak = intersect(gar1, gar2);

        if(isinsegment(tabrak, gar1) && isinsegment(tabrak, gar2)){return true;}
        else{return false;}
    }
};



