// Generated by gencpp from file morpheus_object_detection/timing_msg.msg
// DO NOT EDIT!


#ifndef MORPHEUS_OBJECT_DETECTION_MESSAGE_TIMING_MSG_H
#define MORPHEUS_OBJECT_DETECTION_MESSAGE_TIMING_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace morpheus_object_detection
{
template <class ContainerAllocator>
struct timing_msg_
{
  typedef timing_msg_<ContainerAllocator> Type;

  timing_msg_()
    : Cycletime(0.0)
    , SplitCloud_ProcessTime(0.0)
    , ExtractInitialSeeds_ProcessTime(0.0)
    , RANSAC_ProcessTime(0.0)
    , LineRunClustering_ProcessTime(0.0)
    , EmergencyBrakeEvaluation_ProcessTime(0.0)
    , Total_ProcessTime(0.0)  {
    }
  timing_msg_(const ContainerAllocator& _alloc)
    : Cycletime(0.0)
    , SplitCloud_ProcessTime(0.0)
    , ExtractInitialSeeds_ProcessTime(0.0)
    , RANSAC_ProcessTime(0.0)
    , LineRunClustering_ProcessTime(0.0)
    , EmergencyBrakeEvaluation_ProcessTime(0.0)
    , Total_ProcessTime(0.0)  {
  (void)_alloc;
    }



   typedef float _Cycletime_type;
  _Cycletime_type Cycletime;

   typedef float _SplitCloud_ProcessTime_type;
  _SplitCloud_ProcessTime_type SplitCloud_ProcessTime;

   typedef float _ExtractInitialSeeds_ProcessTime_type;
  _ExtractInitialSeeds_ProcessTime_type ExtractInitialSeeds_ProcessTime;

   typedef float _RANSAC_ProcessTime_type;
  _RANSAC_ProcessTime_type RANSAC_ProcessTime;

   typedef float _LineRunClustering_ProcessTime_type;
  _LineRunClustering_ProcessTime_type LineRunClustering_ProcessTime;

   typedef float _EmergencyBrakeEvaluation_ProcessTime_type;
  _EmergencyBrakeEvaluation_ProcessTime_type EmergencyBrakeEvaluation_ProcessTime;

   typedef float _Total_ProcessTime_type;
  _Total_ProcessTime_type Total_ProcessTime;





  typedef boost::shared_ptr< ::morpheus_object_detection::timing_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::morpheus_object_detection::timing_msg_<ContainerAllocator> const> ConstPtr;

}; // struct timing_msg_

typedef ::morpheus_object_detection::timing_msg_<std::allocator<void> > timing_msg;

typedef boost::shared_ptr< ::morpheus_object_detection::timing_msg > timing_msgPtr;
typedef boost::shared_ptr< ::morpheus_object_detection::timing_msg const> timing_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::morpheus_object_detection::timing_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::morpheus_object_detection::timing_msg_<ContainerAllocator1> & lhs, const ::morpheus_object_detection::timing_msg_<ContainerAllocator2> & rhs)
{
  return lhs.Cycletime == rhs.Cycletime &&
    lhs.SplitCloud_ProcessTime == rhs.SplitCloud_ProcessTime &&
    lhs.ExtractInitialSeeds_ProcessTime == rhs.ExtractInitialSeeds_ProcessTime &&
    lhs.RANSAC_ProcessTime == rhs.RANSAC_ProcessTime &&
    lhs.LineRunClustering_ProcessTime == rhs.LineRunClustering_ProcessTime &&
    lhs.EmergencyBrakeEvaluation_ProcessTime == rhs.EmergencyBrakeEvaluation_ProcessTime &&
    lhs.Total_ProcessTime == rhs.Total_ProcessTime;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::morpheus_object_detection::timing_msg_<ContainerAllocator1> & lhs, const ::morpheus_object_detection::timing_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace morpheus_object_detection

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morpheus_object_detection::timing_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morpheus_object_detection::timing_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morpheus_object_detection::timing_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c259bb8e7add6c69481cffb8a95131c5";
  }

  static const char* value(const ::morpheus_object_detection::timing_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc259bb8e7add6c69ULL;
  static const uint64_t static_value2 = 0x481cffb8a95131c5ULL;
};

template<class ContainerAllocator>
struct DataType< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "morpheus_object_detection/timing_msg";
  }

  static const char* value(const ::morpheus_object_detection::timing_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 Cycletime\n"
"float32 SplitCloud_ProcessTime\n"
"float32 ExtractInitialSeeds_ProcessTime\n"
"float32 RANSAC_ProcessTime\n"
"float32 LineRunClustering_ProcessTime\n"
"float32 EmergencyBrakeEvaluation_ProcessTime\n"
"float32 Total_ProcessTime\n"
;
  }

  static const char* value(const ::morpheus_object_detection::timing_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Cycletime);
      stream.next(m.SplitCloud_ProcessTime);
      stream.next(m.ExtractInitialSeeds_ProcessTime);
      stream.next(m.RANSAC_ProcessTime);
      stream.next(m.LineRunClustering_ProcessTime);
      stream.next(m.EmergencyBrakeEvaluation_ProcessTime);
      stream.next(m.Total_ProcessTime);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct timing_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::morpheus_object_detection::timing_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::morpheus_object_detection::timing_msg_<ContainerAllocator>& v)
  {
    s << indent << "Cycletime: ";
    Printer<float>::stream(s, indent + "  ", v.Cycletime);
    s << indent << "SplitCloud_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.SplitCloud_ProcessTime);
    s << indent << "ExtractInitialSeeds_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.ExtractInitialSeeds_ProcessTime);
    s << indent << "RANSAC_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.RANSAC_ProcessTime);
    s << indent << "LineRunClustering_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.LineRunClustering_ProcessTime);
    s << indent << "EmergencyBrakeEvaluation_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.EmergencyBrakeEvaluation_ProcessTime);
    s << indent << "Total_ProcessTime: ";
    Printer<float>::stream(s, indent + "  ", v.Total_ProcessTime);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MORPHEUS_OBJECT_DETECTION_MESSAGE_TIMING_MSG_H
