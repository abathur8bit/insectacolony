package com.axorion.insecta;

/* *****************************************************************************
 * Copyright 2018 Lee Patterson <https://github.com/abathur8bit>
 *
 * You may use and modify at will. Please credit me in the source.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ******************************************************************************/

import java.util.Date;

/** 
 * Used for timing operations. You start the stopwatch, then can check
 * how long it has been running.  
 *@author Lee Patterson (https://github.com/abathur8bit)
 */
public class Stopwatch {
  Date m_start = null;
  Date m_stop = null;
  long delay = 0;
  long timer = 0;
  
  public Stopwatch()
  {
  }
  
  public Stopwatch(int timerMillis)
  {
	  delay = timerMillis;
	  timer = System.currentTimeMillis();
  }
  
  /** 
   * Update the timer and return if the time has expired. 
   * Resets the timer when it has. 
   * @return true if timer has expired, false otherwise.
   */
  public boolean update()
  {
	  long now = System.currentTimeMillis();
	  if((now-timer) >= 0)
	  {
		  timer = now + delay;
		  return true;
	  }
	  return false;
  }
  
  /**Start the Stopwatch. 
   * Sets the start time to the current time, clears the stop time.
   */
  public void start() {
    m_start = new Date();
    m_stop = null;
  }
  /**Stop the Stopwatch.
   * Sets the stop time to the current time.
   */
  public void stop() {
    m_stop = new Date();
  }
  /**Reset the Stopwatchs start and stop times to zero.
   * If you want to keep timing, you have to call start again.
   */
  public void reset() {
    m_start = null;
    m_stop = null;
  }
  /** 
  * Get the current elapsed time in seconds.If thw stopwatch has
  * been stopped, then we return the elapsed time the stopwatch was 
  * running. If the stopwatch is still running (not been stopped)
  * the elapsed time is the time it was started, to the current time.
  *
  *@return The number of seconds the stop watch has counted.
  */
  public long getSeconds() {
    if(m_start == null)
      return 0;
    if(m_stop==null) {
      Date now = new Date();
      return ((now.getTime() - m_start.getTime())/1000);
    }
      
    return ((m_stop.getTime()-m_start.getTime()) / 1000);
  }
  /** 
  * Get the current elapsed time in milliseconds. If thw stopwatch has
  * been stopped, then we return the elapsed time the stopwatch was 
  * running. If the stopwatch is still running (not been stopped)
  * the elapsed time is the time it was started, to the current time.
  *
  *@return The number of milliseconds the stop watch has counted.
  */
  public long getMilliSeconds() {
    if(m_start == null)
      return 0;
    if(m_stop==null) {
      Date now = new Date();
      return now.getTime() - m_start.getTime();
    }
    return m_stop.getTime() - m_start.getTime();
  }
  
  /**
  * Get a formated string that represents the elapsed time in the format of 
  *
  *  MM:SS:mmm
  *
  * where MM is the number of minutes, SS is the number of seconds from 00-59
  * and mmm is the milliseconds from 0-999. Minutes can range from 0 to 
  * anything.
  *
  *@return Formated string of the elapsed time.
  *@see #getMilliSeconds() , #getSeconds()
  */
  public String getFormated() {
    long now = getMilliSeconds();
    long minutes = now/1000/60;
    long seconds = now/1000-minutes*60;
    long milliseconds = now-(minutes*60+seconds)*1000;
//    String formatedSeconds;
//    if(seconds < 10)
//      formatedSeconds = new String("0"+seconds);
//    else
//      formatedSeconds = new String(""+seconds);
//    return new String(minutes+":"+formatedSeconds+"."+milliseconds);
    return String.format("%02d:%02d.%03d",minutes,seconds,milliseconds);
  }
  
  /** Like calling getFormated */
  public String toString() {
    return getFormated();
  }
}

