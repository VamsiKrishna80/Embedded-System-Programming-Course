volatile char *row_port_dir,*col_port_dir,*row_port_out,*col_port_out;
void init_port()
{
    row_port_dir  = 0x10A;
    col_port_dir  = 0x30;
   row_port_out = 0x10B; 
 col_port_out = 0x31; 
  *row_port_dir = 0xFF;
  *col_port_dir = 0xFF;

}
void delay1( void )
{
  volatile long i;
  for(i=0; i<200000; i++);
}
void displayA()
{
  init_port();
  volatile int i,j=0,Row[7]={0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[7]={0x08,0x14,0x22,0x22,0x3e,0x22,0x22};
 while(j<100)
  {
    for(i=0;i<7;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }

}
void displayB()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x78,0x44,0x44,0x48,0x78,0x44,0x44,0x78};

  while(j<100)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayC()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x00,0x3e,0x40,0x40,0x40,0x40,0x3e,0x00};

  while(j<100)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayD()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x00,0x78,0x44,0x42,0x42,0x44,0x78,0x00};

  while(j<100)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayE()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x7e,0x40,0x40,0x40,0x7e,0x40,0x40,0x7e};

  while(j<100)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displaya()
{
  init_port();
  volatile int i,j=0,Row[7]={0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[7]={0x3c,0x02,0x1e,0x22,0x42,0x46,0x3b};

 while(j<150)
  {
    for(i=0;i<7;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayb()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x40,0x40,0x40,0x7c,0x42,0x42,0x7c,0x00};

 while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayc()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x00,0x3e,0x40,0x40,0x40,0x40,0x3e,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayd()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x02,0x02,0x02,0x1e,0x22,0x22,0x1e,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displaye()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x3c,0x44,0x44,0x78,0x40,0x40,0x3c,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void display0()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x3c,0x42,0x42,0x42,0x42,0x42,0x3c,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void display1()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x08,0x18,0x28,0x48,0x88,0x08,0x08,0xff};

   while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void display2()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x00,0x78,0x04,0x08,0x10,0x20,0x7e,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void display3()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x00,0x7c,0x04,0x04,0x78,0x04,0x04,0x7c};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void display4()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x08,0x18,0x28,0x48,0xff,0x08,0x08,0x08};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayw()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x82,0x82,0x82,0x92,0x92,0x92,0xfe,0x80};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayl()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displaym()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x36,0x49,0x49,0x49,0x49,0x49,0x49,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayo()
{
  init_port();
  volatile int i,j=0,Row[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f},Col[8]={0x3c,0x42,0x42,0x42,0x42,0x42,0x3c,0x00};

  while(j<150)
  {
    for(i=0;i<8;i++)
    {
      *col_port_out=Col[i];
      *row_port_out=Row[i];
      delay(1);
     *row_port_out=0xff;
    } 
    j++;
  }
}
void displayBTw()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0xfe};
 volatile int Row13[2]={0xfd,0xfe},Col13[2]={0xfe,0x92};
  volatile int Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0xfe,0x92,0x92};
   volatile int Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0xfe,0x92,0x92,0x92};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0xfe,0x92,0x92,0x92,0x82};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0xfe,0x92,0x92,0x92,0x82,0x82};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0xfe,0x92,0x92,0x92,0x82,0x82,0x82};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0xfe,0x92,0x92,0x92,0x82,0x82,0x82,0x82};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x92,0x92,0x92,0x82,0x82,0x82,0x82};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x92,0x92,0x82,0x82,0x82,0x82};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0x92,0x82,0x82,0x82,0x82};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x82,0x82,0x82,0x82};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x82,0x82,0x82};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x82,0x82};
      
       volatile int Row[1]={0x7f},Col[1]={0x82};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}

void displayBTe()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0x7e};
 volatile int Row13[2]={0xfd,0xfe},Col13[2]={0x7e,0x80};
  volatile int Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0x7e,0x80,0x80};
   volatile int Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0x7e,0x80,0x80,0xfe};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0x7e,0x80,0x80,0xfe,0x82};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0x7e,0x80,0x80,0xfe,0x82,0x82};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0x7e,0x80,0x80,0xfe,0x82,0x82,0x42};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0x7e,0x80,0x80,0xfe,0x82,0x82,0x42,0x3c};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x80,0x80,0xfe,0x82,0x82,0x42,0x3c};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x80,0xfe,0x82,0x82,0x42,0x3c};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0xfe,0x82,0x82,0x42,0x3c};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x82,0x82,0x42,0x3c};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x82,0x42,0x3c};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x42,0x3c};
      
       volatile int Row[1]={0x7f},Col[1]={0x3c};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}
void displayBTl()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0x10};
 volatile int           Row13[2]={0xfd,0xfe},Col13[2]={0x10,0x10};
  volatile int          Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0x10,0x10,0x10};
   volatile int           Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0x10,0x10,0x10,0x10};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0x10,0x10,0x10,0x10,0x10};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0x10,0x10,0x10,0x10,0x10,0x10};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0x10,0x10,0x10,0x10,0x10,0x10,0x10};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x10,0x10,0x10,0x10,0x10,0x10,0x10};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x10,0x10,0x10,0x10,0x10,0x10};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0x10,0x10,0x10,0x10,0x10};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x10,0x10,0x10,0x10};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x10,0x10,0x10};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x10,0x10};
      
       volatile int Row[1]={0x7f},Col[1]={0x10};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}


void displayBTc()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0x3c};
 volatile int Row13[2]={0xfd,0xfe},Col13[2]={0x3c,0x42};
  volatile int Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0x3c,0x42,0x80};
   volatile int Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0x3c,0x42,0x80,0x80};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0x3c,0x42,0x80,0x80,0x80};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0x3c,0x42,0x80,0x80,0x80,0x82};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0x3c,0x42,0x80,0x80,0x80,0x82,0x42};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0x3c,0x42,0x80,0x80,0x80,0x82,0x42,0x3c};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x42,0x80,0x80,0x80,0x82,0x42,0x3c};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x80,0x80,0x80,0x82,0x42,0x3c};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0x80,0x80,0x82,0x42,0x3c};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x80,0x82,0x42,0x3c};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x82,0x42,0x3c};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x42,0x3c};
      
       volatile int Row[1]={0x7f},Col[1]={0x3c};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}
void displayBTo()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0x3c};
 volatile int Row13[2]={0xfd,0xfe},Col13[2]={0x3c,0x42};
  volatile int Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0x3c,0x42,0x81};
   volatile int Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0x3c,0x42,0x81,0x81};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0x3c,0x42,0x81,0x81,0x81};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0x3c,0x42,0x81,0x81,0x81,0x81};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0x3c,0x42,0x81,0x81,0x81,0x81,0x42};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0x3c,0x42,0x81,0x81,0x81,0x81,0x42,0x3c};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x42,0x81,0x81,0x81,0x81,0x42,0x3c};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x81,0x81,0x81,0x81,0x42,0x3c};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0x81,0x81,0x81,0x42,0x3c};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x81,0x81,0x42,0x3c};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x81,0x42,0x3c};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x42,0x3c};
      
       volatile int Row[1]={0x7f},Col[1]={0x3c};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}
void displayBTm()
{
  init_port();
  volatile int i,j=0,k=0,Row14[1]={0xfe},Col14[1]={0x81};
 volatile int Row13[2]={0xfd,0xfe},Col13[2]={0x81,0x81};
  volatile int Row12[3]={0xfb,0xfd,0xfe},Col12[3]={0x81,0x81,0x81};
   volatile int Row11[4]={0xf7,0xfb,0xfd,0xfe},Col11[4]={0x81,0x81,0x81,0x89};
     volatile int Row10[5]={0xef,0xf7,0xfb,0xfd,0xfe},Col10[5]={0x81,0x81,0x81,0x89,0x89};
  volatile int Row9[6]={0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col9[6]={0x81,0x81,0x81,0x89,0x89,0x89};
  volatile int Row8[7]={0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col8[7]={0x81,0x81,0x81,0x89,0x89,0x89,0x55};
  volatile int Row7[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe},Col7[8]={0x81,0x81,0x81,0x89,0x89,0x89,0x55,0x22};
  
   volatile int Row6[7]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd},Col6[7]={0x81,0x81,0x89,0x89,0x89,0x55,0x22};
    volatile int Row5[6]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb},Col5[6]={0x81,0x89,0x89,0x89,0x55,0x22};
     volatile int Row4[5]={0x7f,0xbf,0xdf,0xef,0xf7},Col4[5]={0x89,0x89,0x89,0x55,0x22};
      volatile int Row3[4]={0x7f,0xbf,0xdf,0xef},Col3[4]={0x89,0x89,0x55,0x22};
      volatile int Row2[3]={0x7f,0xbf,0xdf},Col2[3]={0x89,0x55,0x22};
      volatile int Row1[2]={0x7f,0xbf},Col1[2]={0x55,0x22};
      
       volatile int Row[1]={0x7f},Col[1]={0x22};
        volatile int Row15[1]={0xff},Col15[1]={0x00};
    while(k<250)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row[j];
         *col_port_out=Col[j];
        delay(1);
         *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row1[j];
         *col_port_out=Col1[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
    while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row2[j];
         *col_port_out=Col2[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
       k=0;
    while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row3[j];
         *col_port_out=Col3[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row4[j];
         *col_port_out=Col4[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row5[j];
         *col_port_out=Col5[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
      k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row6[j];
         *col_port_out=Col6[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<8;j++)
      {
        *row_port_out=Row7[j];
         *col_port_out=Col7[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }

       k=0;
     while(k<150)
    {
      for(j=0;j<7;j++)
      {
        *row_port_out=Row8[j];
         *col_port_out=Col8[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<6;j++)
      {
        *row_port_out=Row9[j];
         *col_port_out=Col9[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<5;j++)
      {
        *row_port_out=Row10[j];
         *col_port_out=Col10[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<4;j++)
      {
        *row_port_out=Row11[j];
         *col_port_out=Col11[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<3;j++)
      {
        *row_port_out=Row12[j];
         *col_port_out=Col12[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
     k=0;
     while(k<150)
    {
      for(j=0;j<2;j++)
      {
        *row_port_out=Row13[j];
         *col_port_out=Col13[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
    k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row14[j];
         *col_port_out=Col14[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
       k=0;
     while(k<150)
    {
      for(j=0;j<1;j++)
      {
        *row_port_out=Row15[j];
         *col_port_out=Col15[j];
        delay(1);
        *col_port_out=0x00;
      }
      k++;
    }
}
}



