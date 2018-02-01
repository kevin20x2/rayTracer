#ifndef TRACER_TRIANGLE_H
#define TRACER_TRIANGLE_H
#include "BaseObject.hpp"

template <typename Dtype>
class Triangle : public TracerObject <Dtype>
{
    public:
      Triangle<Dtype>(const Vector3<Dtype> &a_,
      const Vector3<Dtype> &b_,const Vector3<Dtype> &c_) 
      {
          this->_pos = Vector3<Dtype>((a_.x+b_.x+c_.x)/3.0f,
                                       (a_.y+b_.y+c_.y)/3.0f,
                                       (a_.z+b_.z+c_.z)/3.0f
                                       );
          this->a = a_ - this->_pos;
          this->b = b_ - this->_pos;
          this->c = c_ - this->_pos;
          this->_mat._color = Color4(1.0f,1.0f,1.0f);
      }
      bool intersection(const Vector3<Dtype> &origin,
                        const Vector3<Dtype> &dir,
                        Surface<Dtype> &sur, Dtype &l, Dtype &r
                        ) const
      {
          Vector3 <Dtype> _a = TracerObject<Dtype>::_pos + a;
          Vector3 <Dtype> _b = TracerObject<Dtype>::_pos + b;
          Vector3 <Dtype> _c = TracerObject<Dtype>::_pos + c;
          Dtype a_ = _a.x - _b.x;
          Dtype b_ = _b.y - _b.y;
          Dtype c_ = _a.z - _b.z;
          Dtype d_ = _a.x - _c.x;
          Dtype e_ = _a.y - _c.y;
          Dtype f_ = _a.z - _c.z;
          Dtype g_ = dir.x;Dtype h_ = dir.y; Dtype i_ = dir.z;
          Dtype j_ = _a.x - origin.x;
          Dtype k_ = _a.y - origin.y;
          Dtype l_ = _a.z - origin.z;
          Dtype ei = e_*i_; Dtype hf = h_*f_; Dtype eg = e_*g_;
          Dtype gf = g_*f_;Dtype dh = d_*h_;
          Dtype ak = a_*k_; Dtype jb = j_*b_;
          Dtype jc = j_*c_;Dtype al = a_*l_;
          Dtype bl = b_*l_; Dtype kc = k_*c_;
          Dtype M = a_*(ei - hf) + b_*(gf-d_*i_) + c_*(dh-eg);
          Dtype t_ = -(f_*(ak-jb) + e_*(jc -al) + d_*(bl-kc))/M;
          if(t_ < l || t_>r) return false;
          Dtype gamma = (i_*(ak -jb) + h_*(jc-al) + g_*(bl - kc))/M;
          if( gamma < 0 || gamma > 1) return  false;
          Dtype beta = (j_*(ei-hf) + k_*(gf-d_*i_) + l_*(dh-eg))/M;
          if( beta <0 || beta >1-gamma) return false;

          sur._pos = origin + t_ * dir;
          sur._normal = cross((_b-_a),(_c-_a));
          sur._mat = this->_mat;
          r = t_;
          return true;
      }
      protected:
      Vector3 <Dtype> a,b,c;
};

#endif