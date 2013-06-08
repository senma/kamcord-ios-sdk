/*
 *
 * KamcordProtocols.h
 *
 * This declaration contains the KamcordDelegate protocol
 * to receive callbacks about the lifetime of a video.
 *
 */

/*****************************************************************
 *
 * General Kamcord callbacks
 *
 */
@protocol KamcordDelegate <NSObject>

@optional

/*
 *
 * Called when the Kamcord view appears and disappears.
 *
 */
- (void)mainViewDidAppear;
- (void)mainViewWillDisappear;
- (void)mainViewDidDisappear;

/*
 *
 * Called when the Kamcord watch view appears and disappears
 *
 */
- (void)watchViewDidAppear;
- (void)watchViewWillDisappear;
- (void)watchViewDidDisappear;

/*
 *
 * Called when the movie player appears and disappears.
 *
 */
- (void)moviePlayerDidAppear;
- (void)moviePlayerDidDisappear;

/*
 *
 * Called when a thumbnail image for the video is ready.
 *
 * @param       thumbnail       The CGImageRef of the thumbnail for the latest recorded video.
 *
 */
- (void)thumbnailReady:(CGImageRef)thumbnail;


/*
 *
 * Called when the video has finished processing.
 *
 * @param       success         Success will be true if the video processed successfully.
 *
 */
- (void)videoFinishedProcessing:(BOOL)success;

/*
 *
 * Called when the user presses the button in the Gameplay of the Week UI.
 *
 */ 
- (void)notificationCallToActionButtonPressed;

#if KCUNITY_VERSION
/*
 *
 * Called when the thumbnail image for the video is ready.
 *
 * @param       thumbnailFilepath   The local file path to the thumbnail saved to disk.
 *
 */
- (void)thumbnailReadyAtFilePath:(NSString *)thumbnailFilepath;
#endif

/*
 *
 * This is called when the user presses the share button and has successfully
 * authorized with Facebook/Twitter/YouTube. This callback does NOT
 * indicate that the share will successfully begin. The callback below
 * named videoWillUploadToURL: indicates that the video will actually
 * begin uploading.
 *
 * @param       message             The message the user entered.
 * @param       facebook            Share to Facebook selected?
 * @param       twitter             Share to Twitter selected?
 * @param       youtube             Share to YouTube selected?
 * @param       email               Share via email selected?
 *
 */
- (void)shareButtonPressedWithMessage:(NSString *)message
                      shareToFacebook:(BOOL)facebook
                       shareToTwitter:(BOOL)twitter
                       shareToYouTube:(BOOL)youtube
                       shareWithEmail:(BOOL)email;


/*
 *
 * Called when the video has started uploading.
 *
 * @param       kamcordURLString    The web URL of the video once it becomes uploaded.
 *
 */
- (void)videoWillUploadToURL:(NSString *)kamcordURLString;

/*
 *
 * Called when the video has finished uploading or faile dot upload.
 *
 * @param       success             Did the video upload successfully? If the value is NO, there
 *                                  was most likely an issue with the connection quality.
 * @param       videoID             The Kamcord video ID that can be used to query for information
 *                                  about the video.
 *
 */
- (void)videoFinishedUploadingWithSuccess:(BOOL)success
                           kamcordVideoID:(NSString *)videoID;

@end
