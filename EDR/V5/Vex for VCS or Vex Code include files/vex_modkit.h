/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2018, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_modkit.h                                                */
/*    Author:     James Pearman                                               */
/*    Created:    28 March 2018                                               */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef   VCS_VEX_MODKIT_H
#define   VCS_VEX_MODKIT_H

/*-----------------------------------------------------------------------------*/
/** @file    vex_modkit.h
  * @brief   Wrap some of the VCS classes to allow modkit events to work
*//*---------------------------------------------------------------------------*/

// private api needed by modkit build
#ifdef __cplusplus
extern "C" {
#endif
// callback on 1mS interrupt
void vexSystemTimerCallbackInstall( void (*callback)(void) );
// task sleep
void vexTaskSleep( uint32_t time );
// task add
void vexTaskAdd( int (* callback)(void), int interval, char const *label );
// task stop
void vexTaskStop( int (* callback)(void) );
// get task priority
int32_t vexTaskPriorityGet( int (* callback)(void) ) ;
// set task priority
void vexTaskPrioritySet( int (* callback)(void), int32_t priority ) ;

#ifdef __cplusplus
}
#endif

//
// All VCS blocks related classes and variables are now in this single file
//
//

namespace vex { 
  namespace modkit {
    // Globals
    int32_t             PORT1        = vex::PORT1;
    int32_t             PORT2        = vex::PORT2;
    int32_t             PORT3        = vex::PORT3;
    int32_t             PORT4        = vex::PORT4;
    int32_t             PORT5        = vex::PORT5;
    int32_t             PORT6        = vex::PORT6;
    int32_t             PORT7        = vex::PORT7;
    int32_t             PORT8        = vex::PORT8;
    int32_t             PORT9        = vex::PORT9;
    int32_t             PORT10       = vex::PORT10;
    int32_t             PORT11       = vex::PORT11;
    int32_t             PORT12       = vex::PORT12;
    int32_t             PORT13       = vex::PORT13;
    int32_t             PORT14       = vex::PORT14;
    int32_t             PORT15       = vex::PORT15;
    int32_t             PORT16       = vex::PORT16;
    int32_t             PORT17       = vex::PORT17;
    int32_t             PORT18       = vex::PORT18;
    int32_t             PORT19       = vex::PORT19;
    int32_t             PORT20       = vex::PORT20;
    int32_t             PORT21       = vex::PORT21;
    int32_t             PORT22       = vex::PORT22;
    
    percentUnits        percent      = vex::percentUnits::pct;
    timeUnits           seconds      = vex::timeUnits::sec;
    timeUnits           milliseconds = vex::timeUnits::msec;
    currentUnits        amps         = vex::currentUnits::amp;
    powerUnits          watts        = vex::powerUnits::watt;
    torqueUnits         newtonMeters = vex::torqueUnits::Nm;
    torqueUnits         inchPounds   = vex::torqueUnits::InLb;
    rotationUnits       degrees      = vex::rotationUnits::deg;
    rotationUnits       revolutions  = vex::rotationUnits::rev;
    velocityUnits       rpm          = vex::velocityUnits::rpm;

    distanceUnits       milimeters   = vex::distanceUnits::mm;
    distanceUnits       inches       = vex::distanceUnits::in;
    distanceUnits       centimeters  = vex::distanceUnits::cm;

    directionType       forward      = vex::directionType::fwd;
    directionType       reverse      = vex::directionType::rev;
    brakeType           coast        = vex::brakeType::coast;
    brakeType           brake        = vex::brakeType::brake;
    brakeType           hold         = vex::brakeType::hold;

    const color         &black       = vex::black;
    const color         &white       = vex::white;
    const color         &red         = vex::red;
    const color         &green       = vex::green;
    const color         &blue        = vex::blue;
    const color         &yellow      = vex::yellow;
    const color         &orange      = vex::orange;
    const color         &purple      = vex::purple;
    const color         &cyan        = vex::cyan;
    const color         &transparent = vex::transparent;

    fontType            mono12       = vex::fontType::mono12;
    fontType            mono15       = vex::fontType::mono15;
    fontType            mono20       = vex::fontType::mono20;
    fontType            mono30       = vex::fontType::mono30;
    fontType            mono40       = vex::fontType::mono40;
    fontType            mono60       = vex::fontType::mono60;
    fontType            prop20       = vex::fontType::prop20;
    fontType            prop30       = vex::fontType::prop30;
    fontType            prop40       = vex::fontType::prop40;
    fontType            prop60       = vex::fontType::prop60;
    
    /**
     * @brief controller class
     */
    class controller : public ::vex::controller {
      private:
        static void eventHandler(void *arg) {
          if( arg == NULL)
            return;
          
          controller *instance = static_cast<controller *>(arg);
        
          instance->ButtonL1.eventHandler();
          instance->ButtonL2.eventHandler();
          instance->ButtonR1.eventHandler();
          instance->ButtonR2.eventHandler();
          instance->ButtonUp.eventHandler();
          instance->ButtonDown.eventHandler();
          instance->ButtonLeft.eventHandler();
          instance->ButtonRight.eventHandler();
          instance->ButtonA.eventHandler();
          instance->ButtonB.eventHandler();
          instance->ButtonX.eventHandler();
          instance->ButtonY.eventHandler();
          instance->Axis1.eventHandler();
          instance->Axis2.eventHandler();
          instance->Axis3.eventHandler();
          instance->Axis4.eventHandler();
        }
        
      public:
        controller() : controller( controllerType::primary ) {
        };
        controller( controllerType id ) : ::vex::controller(id) {
          vex::event::init( this->_getIndex(), 0xFFFFFFFF, eventHandler, static_cast<void *>(this) );
        };
        ~controller() {};

        class button {
          friend class controller;

          private:
            vex::controller::button  &_button;

            void eventHandler() {
              if( _button.PRESSED )
                PRESSED.triggerEvent();
              if( _button.RELEASED )
                RELEASED.triggerEvent();      
            }

            button( ::vex::controller::button& b ) : _button(b) {};
            ~button() {};
                              
          public:
            /*
             * @prog_lang{block}
             * @brief Event that fires when the button is pressed.
             */
            MODKIT_IO_Event PRESSED  = MODKIT_IO_Event();
            /*
             * @prog_lang{block}
             * @brief Event that fires when the button is released.
             */
            MODKIT_IO_Event RELEASED = MODKIT_IO_Event();

           /**
            * @prog_lang{block|cpp|pro}
            * @drawer_cat{sensing}
            * @block_sig{pressing()}
            * @brief Gets the status of a button.
            * @return Returns a Boolean value based on the pressed states of the button. If the button is pressed it will return true.
            */
            bool     pressing() { return( _button.pressing() ); };        
        };
              
        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonL1}
         * @brief A button that represents the L1 button on the controller
         */      
        button  ButtonL1    = button( ::vex::controller::ButtonL1    );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonL2}
         * @brief A button that represents the L2 button on the controller
         */
        button  ButtonL2    = button( ::vex::controller::ButtonL2    );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonR1}
         * @brief A button that represents the R1 button on the controller
         */
        button  ButtonR1    = button( ::vex::controller::ButtonR1    );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonR2}
         * @brief A button that represents the R2 button on the controller.
         */
        button  ButtonR2    = button( ::vex::controller::ButtonR2    );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonUp}
         * @brief A button that represents the up button on the controller.
         */
        button  ButtonUp    = button( ::vex::controller::ButtonUp    );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonDown}
         * @brief A button that represents the down button on the controller.
         */
        button  ButtonDown  = button( ::vex::controller::ButtonDown  );

       /**
        * @prog_lang{block|cpp|pro}
        * @drawer_cat{instance}
        * @block_sig{Controller.ButtonLeft}
        * @brief A button that represents the left button on the controller.
        */        
        button  ButtonLeft  = button( ::vex::controller::ButtonLeft  );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonRight}
         * @brief A button that represents the right button on the controller.
         */
        button  ButtonRight = button( ::vex::controller::ButtonRight );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonA}
         * @brief A button that represents the A button on the controller.
         */
        button  ButtonA     = button( ::vex::controller::ButtonA     );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonB}
         * @brief A button that represents the B button on the controller.
         */
        button  ButtonB     = button( ::vex::controller::ButtonB     );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonX}
         * @brief A button that represents the x button on the controller.
         */
        button  ButtonX     = button( ::vex::controller::ButtonX     );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.ButtonY}
         * @brief A button that represents the Y button on the controller.
         */
        button  ButtonY     = button( ::vex::controller::ButtonY     );      
      
        class axis  {
          friend class controller;

          private:
            vex::controller::axis  &_axis;
          
            void eventHandler() {
              if( _axis.CHANGED )
                CHANGED.triggerEvent();
            }

            axis( ::vex::controller::axis& j ) : _axis(j) {};
            ~axis() {};
          
          public:
            /*
             * @prog_lang{block}
             * @brief Event that fires when the axis value changes.
             */
            MODKIT_IO_Event CHANGED  = MODKIT_IO_Event();        

            int32_t  value() { return( _axis.value() ); };        

            /**
             * @prog_lang{block|cpp|pro}
             * @drawer_cat{sensing}
             * @block_sig{position(percent)}
             * @cpp_sig{position(vex::percentUnits::pct)}
             * @brief Gets the position of the joystick axis on a scale from -100 to 100.
             * @return Returns an integer that represents the position of the joystick axis as defined by the unit in the parameter.
             * @param units The type of unit that will be returned.
             */         
            int32_t  position( percentUnits units ) { return( _axis.position(units) ); };       
        };      

       /**
        * @prog_lang{block|cpp|pro}
        * @drawer_cat{instance}
        * @block_sig{Controller.Axis1}
        * @brief An axis of a joystick that represents axis 1 on the controller.
        */
        axis     Axis1      = axis( ::vex::controller::Axis1 );

       /**
        * @prog_lang{block|cpp|pro}
        * @drawer_cat{instance}
        * @block_sig{Controller.Axis2}
        * @brief An axis of a joystick that represents axis 2 on the controller.
        */
        axis     Axis2      = axis( ::vex::controller::Axis2 );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.Axis3}
         * @brief An axis of a joystick that represents axis 3 on the controller.
         */
        axis     Axis3      = axis( ::vex::controller::Axis3 );

        /**
         * @prog_lang{block|cpp|pro}
         * @drawer_cat{instance}
         * @block_sig{Controller.Axis4}
         * @brief An axis of a joystick that represents axis 4 on the controller.
         */
        axis     Axis4      = axis( ::vex::controller::Axis4 );
    };

/*-----------------------------------------------------------------------------*/

    /**
     * @brief triport class
     */
    class triport : public ::vex::triport {
      private:
        // Something changed on the triport
        static void eventHandler(void *arg) {
          if( arg == NULL)
            return;
          
          triport *instance = static_cast<triport *>(arg);
        
          instance->A.eventHandler();
          instance->B.eventHandler();
          instance->C.eventHandler();
          instance->D.eventHandler();
          instance->E.eventHandler();
          instance->F.eventHandler();
          instance->G.eventHandler();
          instance->H.eventHandler();
        }
    
      public:
        triport( int32_t index ) : ::vex::triport( index ) {
          vex::event::init( index, 0xFFFFFFFF, eventHandler, static_cast<void *>(this) );
        };
        ~triport() {};

        template <typename... Args>
        triport( int32_t index, Args... args) : ::vex::triport( index, args... ) {}

        class port : public ::vex::triport::port {
          friend class triport;

          private:
            void eventHandler() {
              if( ::vex::triport::port::PRESSED )
                PRESSED.triggerEvent();
              if( ::vex::triport::port::RELEASED )
                RELEASED.triggerEvent();
              if( ::vex::triport::port::CHANGED )
                CHANGED.triggerEvent();
            }
                    
          public:
            port( const int32_t id, triport *parent ) : ::vex::triport::port( id, parent ) {};
            ~port() {};

            /*
             * Low level event used by triport based components
             * DO NOT add "prog_lang{block}" or triport itself will have events
             */
            MODKIT_IO_Event PRESSED  = MODKIT_IO_Event();

            /*
             * Low level event used by triport based components
             * DO NOT add "prog_lang{block}" or triport itself will have events
             */
            MODKIT_IO_Event RELEASED = MODKIT_IO_Event();

            /*
             * Low level event used by triport based components
             * DO NOT add "prog_lang{block}" or triport itself will have events
             */
            MODKIT_IO_Event CHANGED  = MODKIT_IO_Event();

            /*
             * Low level event used by triport based components
             * DO NOT add "prog_lang{block}" or triport itself will have events
             */
            MODKIT_IO_Event &HIGH    = PRESSED;

            /*
             * Low level event used by triport based components
             * DO NOT add "prog_lang{block}" or triport itself will have events
             */
            MODKIT_IO_Event &LOW     = RELEASED;
        };
      
        port  A = port(0, this);
        port  B = port(1, this);
        port  C = port(2, this);
        port  D = port(3, this);
        port  E = port(4, this);
        port  F = port(5, this);
        port  G = port(6, this);
        port  H = port(7, this);
    };

/*-----------------------------------------------------------------------------*/
  
    /**
     * @brief brain class
     */
    class brain : public ::vex::brain {
      private:
        // Something changed on the brain
        static void eventHandler(void *arg) {
          if( arg == NULL)
            return;
          
          brain *instance = static_cast<brain *>(arg);
        
          instance->Screen.eventHandler();
        }
 
      public:
        brain() : ::vex::brain() {
          vex::event::init( this->_getIndex(), 0xFFFFFFFF, eventHandler, static_cast<void *>(this) );
        };
        ~brain() {};


        class lcd : public ::vex::brain::lcd {
          friend class brain;

          private:
            void eventHandler() {
              if( ::vex::brain::lcd::PRESSED )
                PRESSED.triggerEvent();
              if( ::vex::brain::lcd::RELEASED )
                RELEASED.triggerEvent();
            }
          
          public:
            lcd() {};
            ~lcd() {};
            /*
             * @prog_lang{block}
             * @brief Event that fires when the screen is pressed.
             */
            MODKIT_IO_Event PRESSED  = MODKIT_IO_Event();
            /*
             * @prog_lang{block}
             * @brief Event that fires when the screen is released.
             */
            MODKIT_IO_Event RELEASED = MODKIT_IO_Event();
        };
      
        public:
          // Brain has an instance of the lcd
          lcd         Screen;
  
          // Brain has an instance of the internal triport
          triport     ThreeWirePort = vex::modkit::triport( PORT22 );
    };

/*-----------------------------------------------------------------------------*/

    /**
     * @brief competition class
     */
    class competition : public ::vex::competition {
      private:
        static void eventHandler(void *arg) {
          if( arg == NULL)
            return;
          
          competition *instance = static_cast<competition *>(arg);

          // we need to delay events to allow modkit thread manager
          // to be started by main.  If we do not delay, events may
          // be triggered before Modkit_IO_Thread_Manager.init is called.
          vexTaskSleep(20);
          
          instance->eventHandler();
        }

        void eventHandler() {
          if( ::vex::competition::PRE_AUTONOMOUS )
            STARTED_PRE_AUTONOMOUS.triggerEvent();
          if( ::vex::competition::AUTONOMOUS )
            STARTED_AUTONOMOUS.triggerEvent();
          if( ::vex::competition::DRIVER_CONTROL )
            STARTED_DRIVER_CONTROL.triggerEvent();
          if( ::vex::competition::DISABLED )
            DISABLED.triggerEvent();
        }
                  
      public:
        competition() : ::vex::competition() {
          vex::event::init( this->_getIndex(), 0xFFFFFFFF, eventHandler, static_cast<void *>(this) );
        };
        ~competition() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the pre autonomous period starts.
         */
        MODKIT_IO_Event   STARTED_PRE_AUTONOMOUS = MODKIT_IO_Event();
        /*
         * @prog_lang{block}
         * @brief Event that fires when the autonomous period starts.
         */      
        MODKIT_IO_Event   STARTED_AUTONOMOUS     = MODKIT_IO_Event();
        /*
         * @prog_lang{block}
         * @brief Event that fires when the driver control period starts.
         */
        MODKIT_IO_Event   STARTED_DRIVER_CONTROL = MODKIT_IO_Event();
        /*
         * @prog_lang{block}
         * @brief Event that fires when the control system is disabled.
         */
        MODKIT_IO_Event   DISABLED               = MODKIT_IO_Event();
    };

/*-----------------------------------------------------------------------------*/

    /**
     * @brief vision sensor class
     */
    class vision : public ::vex::vision {
        using ::vex::vision::vision;
    };
    
    typedef  vex::vision::signature signature;
    typedef  vex::vision::code      code;

/*-----------------------------------------------------------------------------*/

    /**
     * @brief motor class
     */
    class motor : public ::vex::motor {
      public:
        motor( int32_t index, ::vex::gearSetting gears, bool reverse ) : ::vex::motor(index,gears,reverse) {}
    };

/*-----------------------------------------------------------------------------*/
           
    /**
     * @brief limit switch class
     */
    class limit : public ::vex::limit {
      private:
        modkit::triport::port &_port;
      
      public:
        limit( modkit::triport::port &port ) : ::vex::limit( port ), _port(port) {};
        ~limit() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the limit switch is pressed.
         */
        MODKIT_IO_Event &PRESSED  = _port.PRESSED;
        /*
         * @prog_lang{block}
         * @brief Event that fires when the limit switch is released.
         */
        MODKIT_IO_Event &RELEASED = _port.RELEASED;
    };

    /**
     * @brief bumper switch class
     */
    class bumper : public ::vex::bumper {
      private:
        modkit::triport::port &_port;
      
      public:
        bumper( modkit::triport::port &port ) : ::vex::bumper( port ), _port(port) {};
        ~bumper() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the bumper switch is pressed.
         */
        MODKIT_IO_Event &PRESSED  = _port.PRESSED;
        /*
         * @prog_lang{block}
         * @brief Event that fires when the bumper switch is released.
         */
        MODKIT_IO_Event &RELEASED = _port.RELEASED;
    };  

/*-----------------------------------------------------------------------------*/
  
    /**
     * @brief digital input class
     */
    class digital_in : public ::vex::digital_in {
      private:
        modkit::triport::port &_port;
      
      public:
        digital_in( modkit::triport::port &port ) : ::vex::digital_in( port ), _port(port) {};
        ~digital_in() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the digital in device is high.
         */
        MODKIT_IO_Event &HIGH  = _port.HIGH;
        /*
         * @prog_lang{block}
         * @brief Event that fires when the digital in device is low.
         */
        MODKIT_IO_Event &LOW   = _port.LOW;
    };


    /**
     * @brief digital output class
     */
    class digital_out : public ::vex::digital_out {
      public:
        digital_out( modkit::triport::port &port ) : ::vex::digital_out( port ) {};
        ~digital_out() {};
    };

    /**
     * @brief led class
     */
    class led : public ::vex::led {
      public:
        led( modkit::triport::port &port ) : ::vex::led( port ) {};
        ~led() {};
    };

    /**
     * @brief pneumatics class
     */
    class pneumatics : public ::vex::pneumatics {
      public:
        pneumatics( modkit::triport::port &port ) : ::vex::pneumatics( port ) {};
        ~pneumatics() {};
    };

    /**
     * @brief potentiometer class
     */
    class pot : public ::vex::pot {
      private:
        modkit::triport::port &_port;
      
      public:
        pot( modkit::triport::port &port ) : ::vex::pot( port ), _port(port) {};
        ~pot() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the pot device's value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };
    
    /**
     * @brief line sensor class
     */
    class line : public ::vex::line {
      private:
        modkit::triport::port &_port;
    
      public:
        line( modkit::triport::port &port ) : ::vex::line( port ), _port(port) {};
        ~line() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the line value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };

    /**
     * @brief light sensor class
     */
    class light : public ::vex::light {
      private:
        modkit::triport::port &_port;
  
      public:
        light( modkit::triport::port &port ) : ::vex::light( port ), _port(port) {};
        ~light() {};

        /*
         * @prog_lang{block}
         * @brief Event that fires when the light value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };  
    
    /**
     * @brief gyro class
     */
    class gyro : public ::vex::gyro {
      private:
        modkit::triport::port &_port;
  
      public:
        gyro( modkit::triport::port &port ) : ::vex::gyro( port ), _port(port) {};
        ~gyro() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the gyro value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };    

    /**
     * @brief accelerometer class
     */
    class accelerometer : public ::vex::accelerometer {
      private:
        modkit::triport::port &_port;
  
      public:
        accelerometer( modkit::triport::port &port ) : ::vex::accelerometer( port ), _port(port) {};
        ~accelerometer() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the accelerometer value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };
  
    /**
     * @brief analog input class
     */
    class analog_in : public ::vex::analog_in {
      private:
        modkit::triport::port &_port;
  
      public:
        analog_in( modkit::triport::port &port ) : ::vex::analog_in( port ), _port(port) {};
        ~analog_in() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the analog in device's value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };

    /**
     * @brief encoder class
     */
    class encoder : public ::vex::encoder {
      private:
        modkit::triport::port &_port;
  
      public:
        encoder( modkit::triport::port &port ) : ::vex::encoder( port ), _port(port) {};
        ~encoder() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the encoder value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };

    /**
     * @brief sonar class
     */
    class sonar : public ::vex::sonar {
      private:
        modkit::triport::port &_port;
  
      public:
        sonar( modkit::triport::port &port ) : ::vex::sonar( port ), _port(port) {};
        ~sonar() {};
        /*
         * @prog_lang{block}
         * @brief Event that fires when the sonar value has changed.
         */
        MODKIT_IO_Event &CHANGED  = _port.CHANGED;
    };

    /**
     * @brief pwm output class
     */
    class pwm_out : public ::vex::pwm_out {
      public:
        pwm_out( modkit::triport::port &port ) : ::vex::pwm_out( port ) {};
        ~pwm_out() {};
    };

    /**
     * @brief servo class
     */
    class servo : public ::vex::servo {
      public:
        servo( modkit::triport::port &port ) : ::vex::servo( port ) {};
        ~servo() {};
    };
  
    /**
     * @brief mc29 motor class
     */
    class motor29 : public ::vex::motor29 {
      public:
        motor29( modkit::triport::port &port ) : ::vex::motor29( port ) {};
        ~motor29() {};
    };

    /**
     * @brief victor controller motor class
     */
    class motor_victor : public ::vex::motor_victor {
      public:
        motor_victor( modkit::triport::port &port ) : ::vex::motor_victor( port ) {};
        ~motor_victor() {};
    };
  
  
  };  // END modkit namespace
};  // END vex namespace

#endif // VCS_VEX_MODKIT_H
