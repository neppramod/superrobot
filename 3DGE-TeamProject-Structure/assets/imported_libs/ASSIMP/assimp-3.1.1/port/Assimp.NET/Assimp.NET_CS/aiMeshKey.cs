/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiMeshKey : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiMeshKey(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiMeshKey obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiMeshKey() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiMeshKey(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public double mTime {
    set {
      AssimpPINVOKE.aiMeshKey_mTime_set(swigCPtr, value);
    } 
    get {
      double ret = AssimpPINVOKE.aiMeshKey_mTime_get(swigCPtr);
      return ret;
    } 
  }

  public uint mValue {
    set {
      AssimpPINVOKE.aiMeshKey_mValue_set(swigCPtr, value);
    } 
    get {
      uint ret = AssimpPINVOKE.aiMeshKey_mValue_get(swigCPtr);
      return ret;
    } 
  }

  public aiMeshKey() : this(AssimpPINVOKE.new_aiMeshKey__SWIG_0(), true) {
  }

  public aiMeshKey(double time, uint value) : this(AssimpPINVOKE.new_aiMeshKey__SWIG_1(time, value), true) {
  }

  public bool __equal__(aiMeshKey o) {
    bool ret = AssimpPINVOKE.aiMeshKey___equal__(swigCPtr, aiMeshKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __nequal__(aiMeshKey o) {
    bool ret = AssimpPINVOKE.aiMeshKey___nequal__(swigCPtr, aiMeshKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __smaller__(aiMeshKey o) {
    bool ret = AssimpPINVOKE.aiMeshKey___smaller__(swigCPtr, aiMeshKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __greater__(aiMeshKey o) {
    bool ret = AssimpPINVOKE.aiMeshKey___greater__(swigCPtr, aiMeshKey.getCPtr(o));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}
