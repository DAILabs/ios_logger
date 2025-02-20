//
//  ViewController.h
//  cig_logger
//
//  Created by Mac on 27/08/2018.
//  Copyright © 2018 Mac. All rights reserved.
//

#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>
#import <AVFoundation/AVFoundation.h>
#import <ARKit/ARKit.h>

@interface ViewController : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate, CLLocationManagerDelegate, ARSessionDelegate>
{
    __weak IBOutlet UIImageView *imageView;
    __weak IBOutlet UIButton *button;
    __weak IBOutlet UILabel *runTimeLabel;
    __weak IBOutlet UIButton *afButton;
    __weak IBOutlet UILabel *afLabel;
    __weak IBOutlet UISlider *afSlider;
    __weak IBOutlet UISegmentedControl *segmentedControl;
    __weak IBOutlet UISwitch *accgyroSwitch;
    __weak IBOutlet UISwitch *gpsheadSwitch;
    __weak IBOutlet UISwitch *motionSwitch;
    __weak IBOutlet UISwitch *magnetSwitch;
    __weak IBOutlet UILabel *camLabel;

    AVCaptureSession *session;
    AVCaptureDevice *device;
    AVCaptureDeviceInput *input;
    AVCaptureVideoDataOutput *output;
    dispatch_queue_t sbfQueue;
    
    ARSession *arSession;
    //ARWorldTrackingConfiguration *arConfiguration;
    ARConfiguration *arConfiguration;
    
    CALayer *viewLayer;
    AVCaptureVideoPreviewLayer *captureVideoPreviewLayer;
    
    CMMotionManager *motionManager;
    CLLocationManager *locationManager;
    
    CLLocation *locationData;
    CLHeading *headingData;
    
    bool isRecording;
    bool isStarted;
    bool isAf;
    
    NSString *theDate;
    NSDateFormatter *dateFormat;
    
    double FPS;
    double imuFreq;
    
    NSOperationQueue *accelgyroQueue;
    NSOperationQueue *motionQueue;
    NSOperationQueue *magnetQueue;
    
    NSMutableString  *logStringAccel;
    NSMutableString  *logStringGyro;
    NSMutableString  *logStringMotion; //mot
    NSMutableString  *logStringMotARH; //mot
    NSMutableString  *logStringMotMagnFull; //mot
    NSMutableString  *logStringMagnet; //mag
    NSMutableString  *logStringGps; //gps
    NSMutableString  *logStringHeading; //gps
    NSMutableString  *logStringFrameStamps;
    NSMutableString  *logStringArPose; //arkit
    
    AVAssetWriter *assetWriter;
    AVAssetWriterInput *assetWriterInput;
    AVAssetWriterInputPixelBufferAdaptor *assetWriterInputPixelBufferAdaptor;
    unsigned long frameNum;
    
    float lensPosition;
    
    //----------------
    CGFloat fr_height;
    CGFloat fr_width;
    
    NSTimeInterval bootTime;
    
    NSTimer *_timer;
    int iTimer;
    
    int ireduceFps;
    int reduseFpsInNTimes;
    
    double prevFrTs;
}

- (IBAction)toggleButton:(id)sender;
- (IBAction)toggleAfButton:(id)sender;
- (IBAction)afSliderValueChanged:(id)sender;
- (IBAction)afSliderEndEditing:(id)sender;
- (IBAction)segmentedControlValueChanged:(UISegmentedControl *)sender;
- (IBAction)accgyroSwChanged:(UISwitch *)sender;
- (IBAction)gpsheadSwChanged:(UISwitch *)sender;
- (IBAction)motionSwChanged:(UISwitch *)sender;
- (IBAction)magnetSwChanged:(UISwitch *)sender;

@end
