void main(MultiBuild::Workspace& workspace) {	
	auto project = workspace.create_project(".");
	auto properties = project.properties();

	project.name("simde");
	properties.binary_object_kind(MultiBuild::BinaryObjectKind::eNone);
	project.license("./COPYING");

	project.include_own_required_includes(true);
	project.add_required_project_include({
		"."
	});

	properties.files({
		"./simde/**.h"
	});
}