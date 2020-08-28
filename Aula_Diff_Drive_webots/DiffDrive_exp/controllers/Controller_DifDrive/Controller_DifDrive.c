#include <webots/robot.h>
#include <webots/motor.h>
#include <stdio.h>
#include <math.h>
#include <webots/supervisor.h>

#define TIME_STEP 64
#define MAX_SPEED 6.28

static WbDeviceTag left_motor, right_motor;

int main(int argc, char **argv)
{
  wb_robot_init();
  left_motor = wb_robot_get_device("left wheel motor");
  right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);

  double VR=0.02;  // Velocidade da roda direita (VR)
  double VL;  // Velocidade da roda esquerda (VL)
  double d =0.0565; // metade da dist�ncia do eixo do rob� em metros
  double r=0.0205;
  double R[4] = {0.5,1,1.5,2.0};// Raio da circunferencia que o rob� deve fazer
  int posI=3;
  

 // WbNodeRef robot_node = wb_supervisor_node_get_from_def("MY_ROBOT");
  //WbFieldRef trans_field = wb_supervisor_node_get_field(robot_node, "translation");
  
  

  while (wb_robot_step(TIME_STEP) != -1) {

  //const double *values = wb_supervisor_field_get_sf_vec3f(trans_field);
   // printf("MY_ROBOT is at position: %g %g %g\n", values[0], values[1], values[2]);

 

  /* COLOQUE SEU CODIGO AQUI */  
  VL = VR*((2*R[posI]-d)/(2*R[posI]+d)); 
  double wr = VR/r;
  double wl = VL/r;
  wb_motor_set_velocity(left_motor, wl);
  wb_motor_set_velocity(right_motor, wr);
  

  };
  wb_robot_cleanup();
  return 0;
}