#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		set<string> ret;
		for (int i = 0; i < emails.size(); i++)
		{
			string temp = Findstring(emails[i]);
			ret.insert(temp);
		}
		return ret.size();
	}
	string& Findstring(string& temp)
	{

		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == '@')
				break;
			if (temp[i] == '.')
			{
				temp.erase(i, 1);
			}
			if (temp[i] == '+')
			{
				int pos = temp.find('@');
				temp.erase(i, pos - i);
				break;
			}
		}
		return temp;
	}

};

int main()
{
	//vector<string> a = { "c.o.t.m.f.q+rt.i.l@zuvn.skdsq.com", "d.c.fw.jc.c.gt+w@yzuq.com", "n.kvtb+a.iq.c.l@rupfxkfr.com", "xckqzemg+f.h@hbtp.com", "mh+f.o+k.d.e.x.fe@gywxo.n.com", "d.c.fw.jc.c.gt+q@yzuq.com", "hh.a.fm.jea.s+t@epo.com", "xckqzemg+dx@hbtp.com", "n+gz.fyk+f.oi+e@j.fe.com", "vqvp.p.lvt.t+k@rexcs.com", "nnwhgqn+qm.n@chmgo.com", "mrjrugbrh+e@z.zvnnhswsq.com", "mrjrugbrh+s@z.zvnnhswsq.com", "mh+fclendxh@gywxo.n.com", "t.bgivgn.yh+l@sytfq.mgr.com", "cv.oau.d.zsub+x@ybzkk.com", "oww.sotdsb.j+w@aadoc.r.com", "y.qdv+v+b+bk.di@wd.lvz.com", "nnwhgqn+h.se@chmgo.com", "nnwhgqn+fh.o@chmgo.com", "y.m.v.l.a+f+e+o+m+u@lhn.m.com", "mh+ay.gudhp+x@gywxo.n.com", "bvmztjceb.l+m@uci.com", "c.o.t.m.f.q+i.fy.v@zuvn.skdsq.com", "w.k.uz.n.f.u+uf+l@we.mbb.com", "r.s+lu.b.v.x.t.d+g@yyb.dw.com", "hh.a.fm.jea.s+a@epo.com", "t.bgivgn.yh+o@sytfq.mgr.com", "y.qdv+z.gyuga@wd.lvz.com", "mh+icx.pgzdt@gywxo.n.com", "y.m.v.l.a+m.p+h+as@lhn.m.com", "xckqzemg+w+k@hbtp.com", "y.m.v.l.a+tt.o+h.t@lhn.m.com", "n+l+mcpqdu.th@j.fe.com", "w.k.uz.n.f.u+s+dg@we.mbb.com", "e.pp.o.btp+g+k+v@qqnxdkht.com", "q.y+epj.qb.u.vd@rq.wxd.com", "u+n.p.x+zn.gv.wj@dlkmbenb.ek.com", "mh+dfuaping@gywxo.n.com", "mrjrugbrh+d@z.zvnnhswsq.com", "d.c.fw.jc.c.gt+x@yzuq.com", "n.kvtb+e+p.uu.k@rupfxkfr.com", "e.pp.o.btp+ijv@qqnxdkht.com", "e.pp.o.btp+mew@qqnxdkht.com", "t.bgivgn.yh+x@sytfq.mgr.com", "u+t.fa.f+gtp.em@dlkmbenb.ek.com", "t.bgivgn.yh+u@sytfq.mgr.com", "hh.a.fm.jea.s+c@epo.com", "qro.hxljfov+i@pr.wlw.com", "c.o.t.m.f.q+r.x.o.w@zuvn.skdsq.com", "y.m.v.l.a+e.z+m.lq@lhn.m.com", "y.qdv+uesdrh@wd.lvz.com", "xckqzemg+t.n@hbtp.com", "mh+it+kt.lc.l+r@gywxo.n.com", "nnwhgqn+y.k.m@chmgo.com", "n.kvtb+f.v+o.gh@rupfxkfr.com", "c.o.t.m.f.q+k.uk.s@zuvn.skdsq.com", "d.c.fw.jc.c.gt+d@yzuq.com", "y.qdv+i.q.uikf@wd.lvz.com", "mvvkycizo+w@wbs.j.com", "w.k.uz.n.f.u+icw@we.mbb.com", "qro.hxljfov+m@pr.wlw.com", "mh+nv.m.t+p.l.a.m@gywxo.n.com", "y.qdv+e.piws.f@wd.lvz.com", "y.qdv+fd+fj+x.n@wd.lvz.com", "n+g.f.qv.h.c.t+q.u@j.fe.com", "xckqzemg+gk@hbtp.com", "y.qdv+f.x.f+ptr@wd.lvz.com", "vqvp.p.lvt.t+t@rexcs.com", "e.pp.o.btp+hog@qqnxdkht.com", "cv.oau.d.zsub+u@ybzkk.com", "cv.oau.d.zsub+p@ybzkk.com", "qro.hxljfov+o@pr.wlw.com", "u+jaaow.ena+e@dlkmbenb.ek.com", "y.m.v.l.a+m.w.egc@lhn.m.com", "d.c.fw.jc.c.gt+d@yzuq.com", "yj.g.wm+kn.m.v.t@aicgst.com", "xckqzemg+e.g@hbtp.com", "bvmztjceb.l+a@uci.com", "vqvp.p.lvt.t+r@rexcs.com", "qro.hxljfov+o@pr.wlw.com", "y.qdv+xathpe@wd.lvz.com", "mskkt+lfrso@nfxouykntm.com", "mh+i.koi.hrps@gywxo.n.com", "jc.g+i.jn.x.mrv@dna.f.com", "w.k.uz.n.f.u+wi.u@we.mbb.com", "hazmbrt.nhf+f@aztvolon.com", "hh.a.fm.jea.s+t@epo.com", "cv.oau.d.zsub+e@ybzkk.com", "oww.sotdsb.j+t@aadoc.r.com", "t.bgivgn.yh+c@sytfq.mgr.com", "nnwhgqn+hhf@chmgo.com", "e.pp.o.btp+apm@qqnxdkht.com", "n+ipyouibnd@j.fe.com", "n+y.r.ks.q.z.r.lh@j.fe.com", "mrjrugbrh+r@z.zvnnhswsq.com", "c.o.t.m.f.q+h.vt+r@zuvn.skdsq.com", "xckqzemg+e+v@hbtp.com", "c.o.t.m.f.q+o+v.e+y@zuvn.skdsq.com", "q.y+un.d.d.q+n+or@rq.wxd.com" };
	//vector<string> a = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
	vector<string> a = { "j+ezsorqlmc@rfpycgjuf.com", "j+k+ri+rigt.ad@rfpycgjuf.com", "hfmeqzk.isx+i@fiidmdrsu.com", "j+p+h+d+d+p+z.j.k.g@rfpycgjuf.com", "zygekdy.l.w+s@snh.owpyu.com", "j+m.l+ia+qdgv+w@rfpycgjuf.com", "r+hwbjwefkp@wcjaki.n.com", "zygekdy.l.w+d@snh.owpyu.com", "bizdm+sz.f.a.k@il.cjjlp.com", "hfmeqzk.isx+t@fiidmdrsu.com", "hfmeqzk.isx+i@fiidmdrsu.com", "bizdm+f+j+m.l.l@il.cjjlp.com", "zygekdy.l.w+g@snh.owpyu.com", "r+evgvxmksf@wcjaki.n.com", "hfmeqzk.isx+h@fiidmdrsu.com", "bizdm+lov+cy@il.cjjlp.com", "hfmeqzk.isx+o@fiidmdrsu.com", "bizdm+hs+qao@il.cjjlp.com", "r+v+z+rcuznrj@wcjaki.n.com", "j+r.kn+h.w.a.h+bh@rfpycgjuf.com", "hfmeqzk.isx+t@fiidmdrsu.com", "hfmeqzk.isx+a@fiidmdrsu.com", "zygekdy.l.w+o@snh.owpyu.com", "zygekdy.l.w+i@snh.owpyu.com", "r+vy.u.y+f.er+aw@wcjaki.n.com", "zygekdy.l.w+c@snh.owpyu.com", "bizdm+wztzg@il.cjjlp.com", "j+h.fwbsr+chp@rfpycgjuf.com", "zygekdy.l.w+s@snh.owpyu.com", "zygekdy.l.w+d@snh.owpyu.com", "bizdm+qq.o.q+p@il.cjjlp.com", "zygekdy.l.w+o@snh.owpyu.com", "j+c+zqbq+h.dyt@rfpycgjuf.com", "r+hl.b.i+fz.hz.t@wcjaki.n.com", "r+cbabpf.k+w+e@wcjaki.n.com" };
	cout << a.size() << endl;
	Solution A;
	cout<<A.numUniqueEmails(a)<<endl;
	system("pause");
	return 0;

	
	
}