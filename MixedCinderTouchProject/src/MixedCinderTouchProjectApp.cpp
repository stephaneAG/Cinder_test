// Stéphane Adam Garnier - 2012

// include Cinder lib(s)
#include "cinder/app/AppCocoaTouch.h"
#include "cinder/app/Renderer.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/Camera.h"
#include "cinder/thread.h"


// include standard lib(s)
#include <string>
#include <cstring>
#include <iostream>

// include 3rd party lib(s)
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// include custom lib(s) 

using namespace ci;
using namespace ci::app;

// for boost asio
using namespace boost::asio::ip;

// CINDER APP MAIN CLASS

class MixedCinderTouchProjectApp : public AppCocoaTouch {
  public:
	virtual void	setup();
	virtual void	update();
	virtual void	draw();
    virtual void    shutdown();
    
};

/* // //////////////////////////////////////////////////// APP GLOBAL SCOPE VARIABLES //////////////////////////////////////////////////// // */

boost::asio::io_service theIoService;
udp::socket theSocket( &theIoService, udp::endpoint( udp::v4(), 9700 ) );

/* // //////////////////////////////////////////////////// APP FCNS //////////////////////////////////////////////////// // */

std::string make_daytime_string(){
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

void loopSocketCommunication(){
    try{
    
        for(;;){
            
            boost::array<char, 1> recv_buf;
            udp::endpoint remote_endpoint;
            boost::asio::error_code error;
            
            theSocket.receive_from( asio::buffer( recv_buf, remote_endpoint, 0, error ) );
            
            
        }
        
    } catch( std::exception& e ){
        std::cerr << e.what() << std::endl;
    }
}

/* // //////////////////////////////////////////////////// APP MAIN FUNCTIONS //////////////////////////////////////////////////// // */
void MixedCinderTouchProjectApp::shutdown(){
    std::cout << "[ main ] [ MixedCinderTouchProjectApp::shutdown() ] " << std::endl;
    
    //theIoService.stop();
}


void MixedCinderTouchProjectApp::setup()
{
    std::cout << "[ main ] [ MixedCinderTouchProjectApp::setup() ] " << std::endl;
    
    //boost::thread thePrintWorldThread(boost::bind( &printHelloWorld ) );
    //boost::thread theBoostThread(boost::bind(&boost::asio::io_service::run, &theIoService));
        
}

void MixedCinderTouchProjectApp::update()
{
    std::cout << "[ main ] [ MixedCinderTouchProjectApp::update() ] " << std::endl;
    
    
}

void MixedCinderTouchProjectApp::draw()
{
    std::cout << "[ main ] [ MixedCinderTouchProjectApp::draw() ] " << std::endl;
    
	gl::clear( Color( 0.2f, 0.2f, 0.3f ) );
	
}

CINDER_APP_COCOA_TOUCH( MixedCinderTouchProjectApp, RendererGl )
