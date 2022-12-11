from setuptools import setup

package_name = 'pkg_g2rr'
submodules = 'pkg_g2rr/pygazebo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='u20',
    maintainer_email='u20@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'g2rr = pkg_g2rr.g2rr:main',
        ],
    },
)
